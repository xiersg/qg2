import numpy as np
import pandas as pd
from gmpy2 import random_state
from matplotlib import pyplot as plt
import pandas
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from 预处理 import z_sco
plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置字体为 SimHei（黑体）
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

data = pd.read_csv("data3/bank/bank.csv",sep = ';')
#因为全部挤在一起了，所以用sep参数分割开

data["y"] = data["y"].map({"yes":1,"no":0})#数据标准化
data["poutcome"] = data["poutcome"].map({"unknown":0,"other":0,"failure":-1,"success":1})#数据标准化
data["default"] = data["default"].map({"yes":1,"no":-1})#
data["housing"] = data["housing"].map({"yes":1,"no":-1})
data["loan"] = data["loan"].map({"yes":1,"no":-1})
data["marital"] = data["marital"].map({"married":0,"divorced":0.5,"single":1})
data["age"] = z_sco(data["age"])
#将字符转化成数字

data2 = data.loc[:,["age","marital","default","housing","loan","poutcome","y"]]
y = data2["y"]
x = data2.drop("y",axis = 1)

y = np.array(y)
x = np.array(x)

# 添加偏置
x = np.c_[np.ones(len(y)), x]
x_train,x_temp,y_train,y_temp = train_test_split(x,y,test_size=0.2,random_state= 57)
x_test,x_val,y_test,y_val = train_test_split(x_temp,y_temp,test_size=0.5,random_state= 22)

if __name__ == "__main__":
    print(x_train[2:5])
def sigmoid(z):
    return 1/(1+np.exp(-z))

def loos_js(y,y_hat):#计算交叉熵损失
    return -np.mean(y*np.log(y_hat)+(1-y)*np.log(1-y_hat))

def SIGMOID(x_train,y_train,aerfa,epochs):

    n,m = x_train.shape
    np.random.seed(86)
    w = np.random.randn(m)
    show_loos = []

    for i in range(epochs):#开始迭代
        z = x_train.dot(w)
        #注意形状
        y_hat = sigmoid(z)
        dw = ((1/n)*(x_train.T.dot(y_hat-y_train)))

        w-= aerfa*dw
        if i%int(epochs/20) == 0:
            loss = loos_js(y_train,y_hat)
            print(f"epoch= {i},loss= {loss}")
            show_loos.append([i,loss])

    #列表推导式构建画图的x,y列表
    plt.plot([show_loos[i][0] for i in range(len(show_loos))],[show_loos[i][1] for i in range(len(show_loos))],color = (0.34,0.98,0.23))
    plt.ylabel("损失loss")
    plt.xlabel("迭代次数epoch")
    plt.show()
    return w

def val_test(x_val,y_val,w):
    z = x_val.dot(w)
    y_hat = sigmoid(z)
    loss = loos_js(y_val,y_hat)
    accur_rate = (y_hat>=0.5).astype(int)
    accur_rate = accuracy_score(y_val,accur_rate)
    print(f"损失= {loss}")
    print(f"准确率 = {accur_rate}\n\n")

if __name__ == "__main__":
    w = SIGMOID(x_train,y_train,1,20000)

    print("验证集",end = "")
    val_test(x_val, y_val, w)
    print("测试集",end = "")
    val_test(x_test,y_test,w)
