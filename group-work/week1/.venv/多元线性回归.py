from 预处理 import x_train,x_val,x_test,y_train,y_test,y_val
import numpy as np
from matplotlib import pyplot as plt
import pandas as pd

#添加偏置，用来计算b

def linen_m(x_train,y_train,aerfa,epochs):
    x_train = np.c_[np.ones(x_train.shape[0]), x_train]
    m,n = x_train.shape
    w = np.random.randn(n,)

    for i in range(epochs):
        y_hat = x_train.dot(w)

        #计算误差，不用一步到位，方便算梯度
        error = y_hat-y_train
        #计算梯度
        gradients = (1/m)*x_train.T.dot(error)#公式由偏导数推出
        """注意几个变量的形状"""

        #更新
        w-= aerfa*gradients
        #计算损失
        loss = np.mean(error**2)/2

        if i%int(epochs/10) == 0:
            print(f"epoch= {i} , loss= {loss:.5f}")

    print(f"result_loss = {loss:.5f}")
    return w

w = linen_m(x_train,y_train,0.003,10000)

#val和test用来调参或者用啦测试结果的函数
def linen_val_test(x_val,y_val,w):
    x_val = np.c_[np.ones(x_val.shape[0]), x_val]
    loss = np.mean((x_val.dot(w)-y_val)**2)/2
    print(f"结果{loss:.5f}")

print("\n验证集",end = "")
linen_val_test(x_val,y_val,w)
print("\n测试集",end = "")
linen_val_test(x_test,y_test,w)
