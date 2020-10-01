import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

dataset_csv = pd.read_csv("sample_data.csv")
print(dataset_csv.shape)

print(dataset_csv.head())

X = dataset_csv.drop(["Date","Referee"], axis=1)
print(X)

y = dataset_csv["FTR"]
print(y)







X_train = X[0:15]
X_test = X[15:]
y_train = y[0:15]
y_test = y[15:]

print(X_train.shape)
print(X_test.shape)
print(y_train.shape)
print(y_test.shape)






#Normal Linear SVM

from sklearn.svm import SVC
svClassifierLinear = SVC(kernel="linear")
svClassifierLinear.fit(X_train, y_train)

y_predLin = svClassifierLinear.predict(X_test)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
print("Linear SVM")
print(accuracy_score(y_test, y_predLin))
print(confusion_matrix(y_test, y_predLin))
print(classification_report(y_test, y_predLin))

#Normal Polynomial Kernel SVM

from sklearn.svm import SVC
svClassifierPoly = SVC(kernel="poly", degree = 8)
svClassifierPoly.fit(X_train, y_train)

y_predPol = svClassifierPoly.predict(X_test)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
print("Polynomial Kernel SVM")
print(accuracy_score(y_test, y_predPol))
print(confusion_matrix(y_test, y_predPol))
print(classification_report(y_test, y_predPol))

#Normal rbf Kernel SVM

from sklearn.svm import SVC
svClassifierRbf = SVC(kernel="rbf")
svClassifierRbf.fit(X_train, y_train)

y_predRbf = svClassifierRbf.predict(X_test)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
print("rbf Kernel SVM")
print(accuracy_score(y_test, y_predRbf))
print(confusion_matrix(y_test, y_predRbf))
print(classification_report(y_test, y_predRbf))

















#PCA with Linear SVM

from sklearn.decomposition import PCA
pca = PCA(n_components = 6)
principal_cmpmts = pca.fit_transform(X)
pri_Df = pd.DataFrame(data = principal_cmpmts, columns=["One","Two","Three","Four","Five","Six"])


X_train2 = pri_Df[0:15]
X_test2 = pri_Df[15:]
y_train2 = y[0:15]
y_test2 = y[15:]

from sklearn.svm import SVC
svClassifierLinearPCA = SVC(kernel="linear")
svClassifierLinearPCA.fit(X_train2, y_train2)

y_predLinPCA = svClassifierLinearPCA.predict(X_test2)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
print("PCA Linear SVM")
print(accuracy_score(y_test2, y_predLinPCA))
print(confusion_matrix(y_test2, y_predLinPCA))
print(classification_report(y_test2, y_predLinPCA))

#PCA with Polynomial SVM

from sklearn.decomposition import PCA
pca = PCA(n_components = 6)
principal_cmpmts = pca.fit_transform(X)
pri_Df = pd.DataFrame(data = principal_cmpmts, columns=["One","Two","Three","Four","Five","Six"])


X_train2 = pri_Df[0:15]
X_test2 = pri_Df[15:]
y_train2 = y[0:15]
y_test2 = y[15:]

from sklearn.svm import SVC
svClassifierPolyPCA = SVC(kernel="poly", degree=8)
svClassifierPolyPCA.fit(X_train2, y_train2)

y_predPolPCA = svClassifierPolyPCA.predict(X_test2)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
print("PCA Polynomial SVM")
print(accuracy_score(y_test2, y_predPolPCA))
print(confusion_matrix(y_test2, y_predPolPCA))
print(classification_report(y_test2, y_predPolPCA))

#PCA with Rbf SVM

from sklearn.decomposition import PCA
pca = PCA(n_components = 6)
principal_cmpmts = pca.fit_transform(X)
pri_Df = pd.DataFrame(data = principal_cmpmts, columns=["One","Two","Three","Four","Five","Six"])

X_train2 = pri_Df[0:15]
X_test2 = pri_Df[15:]
y_train2 = y[0:15]
y_test2 = y[15:]

from sklearn.svm import SVC
svClassifierRbfPCA = SVC(kernel="rbf")
svClassifierRbfPCA.fit(X_train2, y_train2)

y_predRbfPCA = svClassifierRbfPCA.predict(X_test2)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
print("PCA RBF SVM")
print(accuracy_score(y_test2, y_predRbfPCA))
print(confusion_matrix(y_test2, y_predRbfPCA))
print(classification_report(y_test2, y_predRbfPCA))






































#KPCA with Linear SVM

from sklearn.decomposition import KernelPCA
kpca = KernelPCA(n_components = 6)
principal_cmpmts = kpca.fit_transform(X)
pri_Df = pd.DataFrame(data = principal_cmpmts, columns=["One","Two","Three","Four","Five","Six"])


X_train2 = pri_Df[0:15]
X_test2 = pri_Df[15:]
y_train2 = y[0:15]
y_test2 = y[15:]

from sklearn.svm import SVC
svClassifierLinearKPCA = SVC(kernel="linear")
svClassifierLinearKPCA.fit(X_train2, y_train2)

y_predLinKPCA = svClassifierLinearKPCA.predict(X_test2)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
print("Kernel PCA Linear SVM")

print(accuracy_score(y_test2, y_predLinKPCA))
print(confusion_matrix(y_test2, y_predLinKPCA))
print(classification_report(y_test2, y_predLinKPCA))

#PCA with Polynomial SVM

from sklearn.decomposition import KernelPCA
kpca = KernelPCA(n_components = 6)
principal_cmpmts = kpca.fit_transform(X)
pri_Df = pd.DataFrame(data = principal_cmpmts, columns=["One","Two","Three","Four","Five","Six"])


X_train2 = pri_Df[0:15]
X_test2 = pri_Df[15:]
y_train2 = y[0:15]
y_test2 = y[15:]

from sklearn.svm import SVC
svClassifierPolyKPCA = SVC(kernel="poly", degree=8)
svClassifierPolyKPCA.fit(X_train2, y_train2)

y_predPolKPCA = svClassifierPolyKPCA.predict(X_test2)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
print("Kernel PCA Polynomial SVM")
print(accuracy_score(y_test2, y_predPolKPCA))
print(confusion_matrix(y_test2, y_predPolKPCA))
print(classification_report(y_test2, y_predPolKPCA))

#PCA with Rbf SVM

from sklearn.decomposition import KernelPCA
kpca = KernelPCA(n_components = 6)
principal_cmpmts = kpca.fit_transform(X)
pri_Df = pd.DataFrame(data = principal_cmpmts, columns=["One","Two","Three","Four","Five","Six"])


X_train2 = pri_Df[0:15]
X_test2 = pri_Df[15:]
y_train2 = y[0:15]
y_test2 = y[15:]

from sklearn.svm import SVC
svClassifierRbfKPCA = SVC(kernel="rbf")
svClassifierRbfKPCA.fit(X_train2, y_train2)

y_predRbfKPCA = svClassifierRbfKPCA.predict(X_test2)

from sklearn.metrics import classification_report, confusion_matrix,accuracy_score
print("Kernel PCA RBF SVM")
print(accuracy_score(y_test2, y_predRbfKPCA))
print(confusion_matrix(y_test2, y_predRbfKPCA))
print(classification_report(y_test2, y_predRbfKPCA))





