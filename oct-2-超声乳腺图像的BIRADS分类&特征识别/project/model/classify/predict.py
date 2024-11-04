import os
import json
import torch
from PIL import Image
from torchvision import transforms
import matplotlib.pyplot as plt
import csv
from vit_model import vit_base_patch16_224_in21k as create_model
import cv2
import numpy as np
import pandas as pd
import re

def main():
    current_dir = os.path.dirname(os.path.abspath(__file__))
    # 默认GPU
    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    
    # 数据预处理，调整大小/中心裁剪/转换为张量/归一化
    data_transform = transforms.Compose(
        [transforms.Resize(256),
         transforms.CenterCrop(224),
         transforms.ToTensor(),
         transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])])
    
    # 读取类别索引文件
    json_path = os.path.join(current_dir, 'class_indices.json')
    assert os.path.exists(json_path), "file: '{}' does not exist.".format(json_path)
    with open(json_path, "r") as f:
        class_indict = json.load(f)
    
    # 创建类别映射
    class_mapping = {
        "class_2": 0,
        "class_3": 1,
        "class_4A": 2,
        "class_4B": 3,
        "class_4C": 4,
        "class_5": 5
    }
    
    # 创建模型
    model = create_model(num_classes=6, has_logits=False).to(device)
    
    # 加载模型权重
    model_weight_path = os.path.join(current_dir, 'weights', 'model-299.pth')
    model.load_state_dict(torch.load(model_weight_path, map_location=device))
    model.eval()
    
    # 预测目录下的所有图片
    img_dir = os.path.join(current_dir, '..', '..', '..', 'testB', 'cla')
    assert os.path.exists(img_dir), "directory: '{}' does not exist.".format(img_dir)

    # 创建输出目录
    output_dir = os.path.join(current_dir, '..', '..')
    output_file = os.path.join(output_dir, "cla_pre.csv")

    total_images = 0

    # 打开CSV文件进行写入（如果文件存在则替换）
    with open(output_file, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["id", "label"])
    
        # 获取 `img_dir` 目录下所有图片文件
        img_files = [os.path.join(img_dir, img_file) for img_file in os.listdir(img_dir) if img_file.endswith(('.jpg', '.png'))]
        print('图片总数量: ', len(img_files))

        # 自定义排序函数，按照文件名中的数字排序
        def sort_key(filename):
            basename = os.path.basename(filename)
            # 使用正则表达式提取文件名中的所有数字
            match = re.match(r'(\d+)', basename)
            if match:
                return int(match.group(1))
            return 0     

        img_files.sort(key=sort_key)
        
        # 预测每张图片
        for img_path in img_files:
            # 读取图像
            image = cv2.imread(img_path)
            # 转换为灰度图
            gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
            # 应用三角法进行二值化
            ret, thresh_triangle = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_TRIANGLE)
            # 形态学操作：去除小的白点
            kernel = np.ones((3, 3), np.uint8)
            thresh_triangle = cv2.morphologyEx(thresh_triangle, cv2.MORPH_OPEN, kernel, iterations=2)
            # 找到轮廓
            contours, _ = cv2.findContours(thresh_triangle, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            if contours:
                largest_contour = max(contours, key=cv2.contourArea)
                x, y, w, h = cv2.boundingRect(largest_contour)
                # 裁剪图像
                cropped_image = image[y:y+h, x:x+w]
            else:
                print(f"未找到轮廓: {img_path}")
                continue
            
            # 将裁剪后的图像转换为PIL格式并进行预测
            img_pil = Image.fromarray(cv2.cvtColor(cropped_image, cv2.COLOR_BGR2RGB))
            img = data_transform(img_pil)
            img = torch.unsqueeze(img, dim=0)
    
            # 预测类别
            with torch.no_grad():
                output = torch.squeeze(model(img.to(device))).cpu()
                predict = torch.softmax(output, dim=0)
                predict_cla = torch.argmax(predict).numpy()
    
            img_name = os.path.basename(img_path)
            img_id = int(os.path.splitext(img_name)[0]) # 不带后缀名
            
            # 根据预测索引获取预测类别名称
            predicted_class = list(class_mapping.keys())[list(class_mapping.values()).index(predict_cla)]
    
            total_images += 1
    
            # 写入CSV文件
            writer.writerow([img_id, predicted_class])
            print("pic: {}       predicted class: {}".format(img_name, predicted_class))
    
            # 打印每个类别的概率
            # for i in range(len(predict)):
            #     print("class: {:10}   prob: {:.3}".format(class_indict[str(i)], predict[i].numpy()))
            # plt.title("class: {}   prob: {:.3}".format(class_indict[str(predict_cla)], predict[predict_cla].numpy()))
            # plt.imshow(img_pil)
            # plt.show()

    # 读取 CSV 文件并映射类别
    df = pd.read_csv(output_file)
    df['label'] = df['label'].map(class_mapping)
    df.to_csv(output_file, index=False)

    print('预测结束, 已生成cla_pre.csv文件')

if __name__ == '__main__':
    main()