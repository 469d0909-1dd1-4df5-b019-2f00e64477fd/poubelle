import matplotlib.pyplot as plt
import numpy as np
%matplotlib inline

f = open("txt/exemple2.1.txt", "r")
f.readline()
data = np.loadtxt(f)
f.close

plt.figure()
plt.plot(data[:,0],data[:,1], "r-")
plt.plot(data[:,0],data[:,2], "b-")
plt.grid()
plt.show()
