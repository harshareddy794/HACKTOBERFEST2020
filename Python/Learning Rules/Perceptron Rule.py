import numpy as np
import math as math
import matplotlib.pyplot as plt
x1=np.array([1,1,-1,-1])
x2=np.array([1,-1,1,-1])
t=np.array([1,-1,-1,-1])
w1=int(0)
w2=int(0)
b=int(0)
a=1
for i in range(len(x1)):
    yin=(x1[i]*w1)+(x2[i]*w2)+b
    print(yin)
    if yin==0:
        y=int(0)
    elif yin>=0:
        y=int(1)
    elif yin<=0:
        y=int(-1)
    if y==t[i]:
        print("No weight updation needed")
    elif y!=t[i]:
        w1new=w1+(a*t[i]*x1[i])
        w2new=w2+(a*t[i]*x2[i])
        bnew=b+(a*t[i])
        w1=w1new
        w2=w2new
        b=bnew
        print("Update the weights")
print(w1)
print(w2)
print(b)
slope=-w1/w2
interc=-b/w2
for ele in t:
    plt.plot(x1,x2,'.g')
for i in range(-10,10):
    y0=(slope*i)+interc
    plt.plot(i,y0,'.b')
plt.show()
