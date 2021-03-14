import matplotlib.pyplot as plt 
import numpy as np

name_list = ['SECP128R1', 'SECP160R1', 'SECP192R1']


plt.xlabel('ECC参数(bits)')
plt.ylabel('计算代价(ms)')

He = [10944,10929,16610]
Jian = [5798,5911,8909]
gkk = [5561,5580,8454]
my = [2845,2890,4358]

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
plt.savefig('fig7.jpg')
plt.show()