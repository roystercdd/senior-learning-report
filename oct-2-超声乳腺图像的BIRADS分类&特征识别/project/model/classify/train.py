import os
import math
import argparse

import torch
import torch.optim as optim
import torch.optim.lr_scheduler as lr_scheduler
from torch.utils.tensorboard import SummaryWriter
from torchvision import transforms

from my_dataset import MyDataSet
from vit_model import vit_base_patch16_224_in21k as create_model
from utils import read_split_data, train_one_epoch, evaluate

# 图像预处理→裁剪
import cv2
import numpy as np

def preprocess():
    # 输入和输出根目录
    input_root_dir = './data/cla_all'
    output_root_dir = './data/cla_train_preprocessed'
    # 定义子文件夹
    classes = ['class_2', 'class_3', 'class_4A', 'class_4B', 'class_4C', 'class_5']
    for class_name in classes:
        # 为每个子文件夹创建相应的输出路径
        input_dir = os.path.join(input_root_dir, class_name)
        output_dir = os.path.join(output_root_dir, class_name)
        # 创建输出文件夹（如果不存在）
        os.makedirs(output_dir, exist_ok=True)
        # 获取目录下所有文件
        files = os.listdir(input_dir)
        # 打印每个子文件夹中的图片总数
        print(f"{class_name} 文件夹下共有 {len(files)} 张图片")
        for file in files:
            # 检查文件扩展名
            if file.endswith('.png') or file.endswith('.jpg'):
                # 读取图像
                image = cv2.imread(os.path.join(input_dir, file))
                # 转换为灰度图
                gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
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
                    cropped_image = image[y:y + h, x:x + w]
                    # 保存裁剪后的图像
                    output_path = os.path.join(output_dir, file)
                    cv2.imwrite(output_path, cropped_image)
                else:
                    print(f"未找到轮廓: {file} in {class_name}")
    # Q:图像预处理后保存在preprocessed_output_image里, 但是曾被转换为了灰度图, 我在想, 转换为灰度图过后进行预测是否拉低了精度?
    print("-----图像预处理完成-----")

def main(args):
    # 默认使用GPU
    device = torch.device(args.device if torch.cuda.is_available() else "cpu")
    # 创建权重保存目录
    if os.path.exists("./weights") is False:
        os.makedirs("./weights")
    # TensorBoard
    tb_writer = SummaryWriter()
    # 读取训练和验证数据的路径和标签,args是main函数的参数
    train_images_path, train_images_label, val_images_path, val_images_label = read_split_data(args.data_path)
    

    # 预处理操作v1,包括随即裁剪/水平翻转/归一化
    # data_transform = {
    #     "train": transforms.Compose([transforms.RandomResizedCrop(224),
    #                                  transforms.RandomHorizontalFlip(),
    #                                  transforms.ToTensor(),
    #                                  transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])]),
    #     "val": transforms.Compose([transforms.Resize(256),
    #                                transforms.CenterCrop(224),
    #                                transforms.ToTensor(),
    #                                transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])])}


    # 数据预处理v2, 加入训练集resize
    data_transform = {
        "train": transforms.Compose([transforms.Resize((256,256)),
                                     transforms.CenterCrop(224),
                                     transforms.ToTensor(),
                                     transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])]),
        "val": transforms.Compose([transforms.Resize((256,256)),
                                   transforms.CenterCrop(224),
                                   transforms.ToTensor(),
                                   transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])])}

    # 数据预处理v3, 加入随机水平翻转及色彩调整
    # data_transform = {
    #     "train": transforms.Compose([
    #         transforms.Resize((256, 256)),                       # 调整大小到256x256
    #         transforms.RandomHorizontalFlip(p=0.5),              # 以50%的概率随机水平翻转
    #         transforms.RandomRotation(degrees=15),               # 以15度范围内随机旋转
    #         transforms.ColorJitter(brightness=0.2, contrast=0.2, saturation=0.2, hue=0.1), # 随机调整亮度、对比度、饱和度和色调
    #         transforms.CenterCrop(224),                          # 中心裁剪到224x224
    #         transforms.ToTensor(),                               # 转换为Tensor
    #         transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])  # 归一化
    #     ]),
    #     "val": transforms.Compose([
    #         transforms.Resize((256, 256)),                       # 调整大小到256x256
    #         transforms.CenterCrop(224),                          # 中心裁剪到224x224
    #         transforms.ToTensor(),                               # 转换为Tensor
    #         transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])  # 归一化
    #     ])
    # }



    # 实例化训练数据集,自定义数据集类MyDataSet
    train_dataset = MyDataSet(images_path=train_images_path,
                              images_class=train_images_label,
                              transform=data_transform["train"])

    # 实例化验证数据集
    val_dataset = MyDataSet(images_path=val_images_path,
                            images_class=val_images_label,
                            transform=data_transform["val"])

    # 创建数据加载器
    # 批量大小,是否打乱数据,使用CPU核心数,微调请注意
    batch_size = args.batch_size
    nw = min([os.cpu_count(), batch_size if batch_size > 1 else 0, 8])  # 设置欧泡零大小
    print('Using {} dataloader workers every process'.format(nw))
    train_loader = torch.utils.data.DataLoader(train_dataset,
                                               batch_size=batch_size,
                                               shuffle=True,
                                               pin_memory=True,
                                               num_workers=nw,
                                               collate_fn=train_dataset.collate_fn)

    val_loader = torch.utils.data.DataLoader(val_dataset,
                                             batch_size=batch_size,
                                             shuffle=False,
                                             pin_memory=True,
                                             num_workers=nw,
                                             collate_fn=val_dataset.collate_fn)

    model = create_model(num_classes=args.num_classes, has_logits=False).to(device)

    # 加载预训练权重
    if args.weights != "":
        assert os.path.exists(args.weights), "weights file: '{}' not exist.".format(args.weights)
        weights_dict = torch.load(args.weights, map_location=device)
        # 删除不需要的权重
        del_keys = ['head.weight', 'head.bias'] if model.has_logits \
            else ['pre_logits.fc.weight', 'pre_logits.fc.bias', 'head.weight', 'head.bias']
        for k in del_keys:
            del weights_dict[k]
        print(model.load_state_dict(weights_dict, strict=False))

    # 冻结部分层的参数
    if args.freeze_layers:
        for name, para in model.named_parameters():
            # 除head, pre_logits外，其他权重全部冻结
            if "head" not in name and "pre_logits" not in name:
                para.requires_grad_(False)
            else:
                print("training {}".format(name))

    # 设置优化器和学习率调度器,余弦退火
    pg = [p for p in model.parameters() if p.requires_grad]
    optimizer = optim.SGD(pg, lr=args.lr, momentum=0.9, weight_decay=5E-5) # SGD优化器
    # Scheduler https://arxiv.org/pdf/1812.01187.pdf
    lf = lambda x: ((1 + math.cos(x * math.pi / args.epochs)) / 2) * (1 - args.lrf) + args.lrf  # cosine
    scheduler = lr_scheduler.LambdaLR(optimizer, lr_lambda=lf)

    # 对每个迭代
    for epoch in range(args.epochs):
        # 训练模型
        train_loss, train_acc = train_one_epoch(model=model,
                                                optimizer=optimizer,
                                                data_loader=train_loader,
                                                device=device,
                                                epoch=epoch)

        scheduler.step() # 更新学习率

        # 验证模型
        val_loss, val_acc = evaluate(model=model,
                                     data_loader=val_loader,
                                     device=device,
                                     epoch=epoch)

        # 这个是Tensorboard? 记录训练和验证指标
        tags = ["train_loss", "train_acc", "val_loss", "val_acc", "learning_rate"]
        tb_writer.add_scalar(tags[0], train_loss, epoch)
        tb_writer.add_scalar(tags[1], train_acc, epoch)
        tb_writer.add_scalar(tags[2], val_loss, epoch)
        tb_writer.add_scalar(tags[3], val_acc, epoch)
        tb_writer.add_scalar(tags[4], optimizer.param_groups[0]["lr"], epoch)
        # 保存权重
        torch.save(model.state_dict(), "./weights/model-{}.pth".format(epoch))

# 作为主程序进行
if __name__ == '__main__':
    # 先进行图像的预处理
    preprocess()
    # 参数解析器
    parser = argparse.ArgumentParser()
    # 添加命令行参数
    parser.add_argument('--num_classes', type=int, default=6) # 类别数,2~5
    parser.add_argument('--epochs', type=int, default=300) # epochs
    parser.add_argument('--batch-size', type=int, default=8) # 批量大小
    parser.add_argument('--lr', type=float, default=0.001)
    parser.add_argument('--lrf', type=float, default=0.01)

    # 数据集所在根目录
    # https://storage.googleapis.com/download.tensorflow.org/example_images/flower_photos.tgz
    # 只设置了数据集所在目录,没有设置标签,因为标签来自于文件目录名
    parser.add_argument('--data-path', type=str,
                        default="./data/cla_train_preprocessed")
    parser.add_argument('--model-name', default='ViT用于超声乳腺图像分类', help='create model name')

    # 预训练权重路径，如果不想载入就设置为空字符（但是效果会很从差）,用的是vit_l, patch_size=16
    parser.add_argument('--weights', type=str, default='./vit_base_patch16_224_in21k.pth',
                        help='initial weights path')
    # 是否冻结权重
    parser.add_argument('--freeze-layers', type=bool, default=True)
    parser.add_argument('--device', default='cuda:0', help='device id (i.e. 0 or 0,1 or cpu)')

    opt = parser.parse_args()

    main(opt) # 调用main,opt是args,opt来自对parse_args的解析

