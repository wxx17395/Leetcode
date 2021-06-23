# -*- coding=utf-8 -*-
import matplotlib.pyplot as plt
import numpy as np

import matplotlib
matplotlib.rc("font",family='STSong')

name_list = ['SECP128R1', 'SECP160R1', 'SECP192R1']

plt.xlabel('ECC Parameters (bits)')
plt.ylabel('Computation cost(ms)')

He = [10944,10929,16610]
Jian = [5798,5911,8909]
gkk = [5561,5580,8454]
my = [2845,2890,4358]

#所有数据和柱子
data =[]
data.append(He)
data.append(Jian)
data.append(gkk)
data.append(my)
bars = []

x=[0,1,2]
total_width, n = 0.6, 4
width = total_width / n

bars.append(plt.bar(x, He, width=width, label='HZKL', fc='red'))
for i in range(len(x)):
    x[i] = x[i] + width
bars.append(plt.bar(x, Jian, width=width, label='SGJ', tick_label=name_list, fc='gold'))
for i in range(len(x)):
    x[i] = x[i] + width
bars.append(plt.bar(x, gkk, width=width, label='GKK', tick_label=name_list, fc='purple'))
for i in range(len(x)):
    x[i] = x[i] + width
bars.append(plt.bar(x, my, width=width, label='Our scheme', tick_label=name_list, fc='mediumblue'))
plt.legend()

#添加数字
for j in range(len(bars)):
    bars1 = bars[j]
    data_i = data[j]
    for i, rec in enumerate(bars1):
        x_text = rec.get_x()# 获取柱形图横坐标 可以+/-数值使其居中
        if data_i[i] > 10000:
            x_text -= width / 8
        y_text = rec.get_height() + 30# 获取柱子的高度 +0.02
        plt.text(x_text, y_text, data_i[i], fontsize=8)
plt.savefig('计算代价.pdf')
plt.show()