import matplotlib.pyplot as plt 
import numpy as np

name_list = ['SECP128R1', 'SECP160R1', 'SECP192R1']


plt.xlabel('ECC Parameters (bits)')
plt.ylabel('Storage cost (bits)')

He = [768,1088,1600]
Jian = [832,1184,1728]
gkk = [832,1184,1728]
my = [960,1344,1920]

x=[0,1,2]
total_width, n = 0.6, 4
width = total_width / n

plt.bar(x, He, width=width, label='HZKL', fc='red')

for i in range(len(x)):
    x[i] = x[i] + width
plt.bar(x, Jian, width=width, label='SGJ', tick_label=name_list, fc='gold')
for i in range(len(x)):
    x[i] = x[i] + width
plt.bar(x, gkk, width=width, label='GKK', tick_label=name_list, fc='purple')
for i in range(len(x)):
    x[i] = x[i] + width
plt.bar(x, my, width=width, label='Our scheme', tick_label=name_list, fc='mediumblue')
plt.legend()
plt.savefig('fig5.jpg')
plt.show()