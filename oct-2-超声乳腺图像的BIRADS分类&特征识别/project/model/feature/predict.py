from PIL import Image
import numpy as np
import torch
import torchvision.transforms as transforms
from model import MultiOutputModel
from option import get_args
import os
import csv
import re
import cv2

mean =[ 0.29489932, 0.29274837, 0.30230914]
std = [0.17007888, 0.16899402, 0.17257325]
args = get_args()
batch_size = args.batch_size
num_workers = args.num_workers
device = args.device
original_csv_path = args.original_csv_path
val_csv_path = args.val_csv_path
checkpoint = args.checkpoint
predict_image_path = args.predict_image_path


def characteristic():
    # 获取当前脚本文件所在的目录路径
    current_dir = os.path.dirname(os.path.abspath(__file__))

    val_transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize(mean, std)
    ])

    model = torch.load(checkpoint, map_location='cpu')
    image_dir = os.path.join(current_dir, '..', '..', '..', 'testB', 'fea')
    # CSV 文件路径
    csv_file_path = os.path.join(current_dir, '..', '..', 'fea_pre.csv')
    
    count = 0
    
    # 检查目录是否存在
    if not os.path.exists(image_dir):
        print(f"Directory {image_dir} does not exist.")
    else:
        image_files = os.listdir(image_dir)

        # 自定义排序函数，按照文件名中的数字排序
        def sort_key(filename):
            # 使用正则表达式提取文件名中的所有数字
            match = re.match(r'(\d+)', filename)
            if match:
                # 将提取的数字部分转换成整数
                return int(match.group(1))
            else:
                # 如果没有匹配到数字，返回一个默认值（例如0）
                return 0

        # 使用自定义的排序键来排序文件列表
        image_files.sort(key=sort_key)

        # 打开 CSV 文件准备写入
        with open(csv_file_path, 'w', newline='') as csv_file:
            # 创建 CSV 写入器
            writer = csv.writer(csv_file)
            # 写入标题行
            writer.writerow(['id', 'boundary', 'calcification', 'direction', 'shape'])

            # 循环处理每个文件
            for image_file in image_files:
                # if count == 10:
                #     break
                count +=1
                # 构造完整的文件路径
                predict_image_path = os.path.join(image_dir, image_file)

                # 使用 cv2.imread 打开图像文件
                img = cv2.imread(predict_image_path)

                # 检查图像是否成功加载
                if img is None:
                    print("图像文件未能加载，请检查路径。")
                else:
                    # 转换为灰度图
                    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

                    # 应用三角法进行二值化
                    ret, thresh_triangle = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_TRIANGLE)

                    # 形态学操作：去除小的白点
                    kernel = np.ones((3, 3), np.uint8)
                    thresh_triangle = cv2.morphologyEx(thresh_triangle, cv2.MORPH_OPEN, kernel, iterations=2)

                    # 找到轮廓
                    contours, _ = cv2.findContours(thresh_triangle, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

                    # 找到最大的轮廓
                    if contours:
                        largest_contour = max(contours, key=cv2.contourArea)
                        # 计算轮廓的边界框
                        x, y, w, h = cv2.boundingRect(largest_contour)
                        # 裁剪图像
                        cropped_img = img[y:y + h, x:x + w]

                        # 将裁剪后的 NumPy 数组转换为 PIL 图像对象
                        cropped_image = Image.fromarray(cropped_img)
                    else:
                        print("未找到轮廓")

                    # 确保图像是 RGB 模式
                    if cropped_image.mode != 'RGB':
                        cropped_image = cropped_image.convert('RGB')

                    # 应用验证集转换
                    cropped_image_tensor = val_transform(cropped_image).unsqueeze(0)

                    # 不追踪梯度
                    with torch.no_grad():
                        # 模型预测
                        outputs = model(cropped_image_tensor)

                        _, predicted_boundary = outputs['boundary'].cpu().max(1)
                        _, predicted_calcification = outputs['calcification'].cpu().max(1)
                        _, predicted_direction = outputs['direction'].cpu().max(1)
                        _, predicted_shape = outputs['shape'].cpu().max(1)


                        def swa(real):
                            if (real == 1):
                                return 0
                            else:
                                return 1


                        # 写入一行数据到 CSV 文件
                        writer.writerow([
                            count, # 不足两位增加前导0
                            swa(predicted_boundary.item()),
                            swa(predicted_calcification.item()),
                            swa(predicted_direction.item()),
                            swa(predicted_shape.item())
                        ])

    print('预测结束, 已生成fea_pre.csv文件')

if __name__ == '__main__':
    characteristic()
