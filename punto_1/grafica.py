import matplotlib.pyplot as plt
import numpy as np
datos= np.loadtxt("datos.dat")
v=[]
Ex=[]
Ey=[]
for i in range(250):
	v.append(datos[:,i])
	Ex.append(datos[:,i+250])
	Ey.append(datos[:,i+(250*2)])
v=np.transpose(v)
Ex=np.transpose(Ex)
Ey=np.transpose(Ey)
Ex=np.array(Ex)
Ey=np.array(Ey)
x=np.array(range(250))
plt.figure(figsize=(10,10))
plt.imshow(v)
plt.streamplot(x,x,Ex,Ey)
plt.xlim((0,250))
plt.ylim((250,0))
plt.savefig("placas.pdf")
