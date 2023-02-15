import numpy as np 

n = 5; 
a = np.random.rand(n,n).round(2)*100
b = np.random.rand(n,n).round(2)*100

sa = np.array([[1,2],[3,4]])
sb = np.array([[4,3],[1,2]])
va = np.random.rand(n).round(2)*100
vb = np.random.rand(n).round(2)*100

vadotvb = np.dot(va,vb)
print(va)
print(vb)

dotpro  = 0;

for i , j in zip(va,vb):
    dotpro += i*j

print(dotpro)
print("vadotvb = ",vadotvb)

print(a@b) # matrix cross product
print(sa@sb)
