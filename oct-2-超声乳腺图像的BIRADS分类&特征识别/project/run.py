import subprocess
import os

# 定义路径
classify_predict_path = os.path.join('model', 'classify', 'predict.py')
feature_predict_path = os.path.join('model', 'feature', 'predict.py')

# 执行 classify 目录下的 predict.py
subprocess.run(['python', classify_predict_path])

# 执行 feature 目录下的 predict.py
subprocess.run(['python', feature_predict_path])