import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsRegressor
from sklearn.metrics import classification_report
from sklearn import datasets

# data=datasets.load_iris()
# x=data.data[:,:2]
# y=data.target
#
# range_k=range(1,21)
# accuracies=[]
# x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2,random_state=666)
# for k in range_k:
#     knn=KNeighborsClassifier(n_neighbors=k)
#     knn.fit(x_train,y_train)
#     y_pred=knn.predict(x_test)
#     accuracy=knn.score(x_test,y_test)
#     accuracies.append(accuracy)

# plt.plot(range_k, accuracies, marker='o')
# plt.title("K值与准确率的关系")
# plt.xlabel("K值")
# plt.ylabel("准确率")
# plt.show()

# h = .02  # 网格步长
# x_min, x_max = x[:, 0].min() - 1, x[:, 0].max() + 1
# y_min, y_max = x[:, 1].min() - 1, x[:, 1].max() + 1
#
# # 创建一个二维网格，表示不同的样本空间
# xx, yy = np.meshgrid(np.arange(x_min, x_max, h),
#                      np.arange(y_min, y_max, h))
#
# # 使用KNN模型预测网格中的每个点的类别
# Z = knn.predict(np.c_[xx.ravel(), yy.ravel()])
# Z = Z.reshape(xx.shape)
#
# # 绘制决策边界
# plt.contourf(xx, yy, Z, alpha=0.8)
#
# # 绘制训练数据点
# plt.scatter(x[:, 0], x[:, 1], c=y, edgecolors='k', marker='o', s=50)
# plt.title("KNN Demo")
# plt.xlabel("Feature 1")
# plt.ylabel("Feature 2")
# plt.show()
X=np.random.rand(100,1)*10
y=np.sin(X).ravel()+0.1*np.random.randn(100)

x_train,x_test,y_train,y_test=train_test_split(X,y,test_size=0.3,random_state=42)
knn = KNeighborsRegressor(n_neighbors=5)
knn.fit(x_train,y_train)
y_pred = knn.predict(x_test)
score=knn.score(x_test,y_test)
print(score)
plt.scatter(x_test, y_test, color='red', label='True Values')
plt.scatter(x_test, y_pred, color='blue', label='Predicted Values')
plt.title("KNN Regression")
plt.xlabel("Feature")
plt.ylabel("Target")
plt.legend()
plt.show()