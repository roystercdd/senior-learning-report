import torch
import torch.nn as nn
import torchvision.models as models


class MultiOutputModel(nn.Module):
    def __init__(self, n_boundary_classes, n_calcification_classes, n_direction_classes,n_shape_classes):
        super().__init__()

        self.base_model = models.mobilenet_v2().features
        last_channel = models.mobilenet_v2().last_channel

        self.pool = nn.AdaptiveAvgPool2d((1, 1))

        # Create three independent classifiers for predicting three categories
        self.boundary = nn.Sequential(nn.Dropout(p=0.2), nn.Linear(in_features=last_channel, out_features=n_boundary_classes))
        self.calcification = nn.Sequential(nn.Dropout(p=0.2), nn.Linear(in_features=last_channel, out_features=n_calcification_classes))
        self.direction = nn.Sequential(nn.Dropout(p=0.2), nn.Linear(in_features=last_channel, out_features=n_direction_classes))
        self.shape = nn.Sequential(nn.Dropout(p=0.2), nn.Linear(in_features=last_channel, out_features=n_shape_classes))
    def forward(self, x):
        x = self.base_model(x)
        x = self.pool(x)

        x = torch.flatten(x, 1)

        return {
            'boundary': self.boundary(x),
            'calcification': self.calcification(x),
            'direction': self.direction(x),
            'shape': self.shape(x),
        }
