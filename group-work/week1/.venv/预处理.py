from data_c import data
import numpy as np
from matplotlib import pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import RobustScaler

y = data.iloc[:,-1]
x = data.drop("MEDV",axis = 1)

_,m = x.shape
col_name = data.columns.tolist()


def z_sco(col):  # 使数据减去均值除以标准差，以进行标准化
    return (col - col.mean()) / col.std()

def max_min(col):#使用最大最小值进行归一化
   return (col-col.min())/(col.max()-col.min())

def bzh(x,y):#传入两个x 和 y DataFrame 和 pd_Serise

    # 似乎数据范围不是很大，并且不需要进行向量相似比较操作，所以只选择了两种标准化方法

    x["CRIM"] = max_min(x["CRIM"])
    x["ZN"] = max_min(x["ZN"])
    x["AGE"] = max_min(x["AGE"])
    x["LSTAT"] = max_min(x["LSTAT"])
    x["TAX"] = z_sco(x['TAX'])
    x["B"] = z_sco(x['B'])
    x["RAD"] = x["RAD"]/10
    return (x,y)

x2,y2 = x.iloc[:],y.iloc[:]
x2,y2 = bzh(x2,y2)
var1,var2 = [],[]
if __name__ == "__main__":
    for i in range(m):
        print(f"列名{col_name[i]},var = {x.iloc[:, i].var()}")
        var1.append(x.iloc[:, i].var())
    print("\n\n")

    for i in range(m):
        print(f"列名{col_name[i]},var = {x2.iloc[:, i].var()}")
        var2.append(x2.iloc[:, i].var())

    show_x1 = np.arange(2,2+m*6,6)#其实这个分析没什么用，就是看看哪个方差要降一点
    show_x2 = np.arange(4,2+m*6,6)
    plt.bar(show_x1,var1,width = 3,label = "方差",color=(0.66,0.87,0.45))
    plt.bar(show_x2, var2, width=3, label="方差", color=(0.87,0.12,0.15))
    plt.show()

x = np.array (x2)
y = np.array(y2)

#分数据
x_train,x_temp,y_train,y_temp = train_test_split(x,y,test_size = 0.2,random_state = 58)
x_val,x_test,y_val,y_test = train_test_split(x_temp,y_temp,test_size = 0.5,random_state = 68)
if __name__ == "__main__":
    print(f"train_size  {len(y_train)}\nval_size  {len(y_val)},\ntest_size  {len(y_test)}")