import matplotlib.pyplot as plt
import numpy as np
%matplotlib inline

f = np.loadtxt("txt/exemple2.3.txt", "r")

plt.figure()
plt.plot(data[:,0],data[:,1], "r-")
plt.plot(data[:,0],data[:,2], "b-")
plt.grid()
plt.show()
