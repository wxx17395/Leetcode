# -*- coding=utf-8 -*-
import matplotlib.pyplot as plt
import numpy as np

import matplotlib
matplotlib.rc("font",family='STSong')

# from matplotlib.font_manager import FontManager
# import subprocess
#
# mpl_fonts = set(f.name for f in FontManager().ttflist)
#
# print('all font list get from matplotlib.font_manager:')
# for f in sorted(mpl_fonts):
#     print('\t' + f)

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

#所有数据和柱子
data =[]
data.append(He)
data.append(Jian)
data.append(gkk)
data.append(my)
bars = []

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


#添加数字
for j in range(len(bars)):
    bars1 = bars[j]
    data_i = data[j]
    for i, rec in enumerate(bars1):
        x_text = rec.get_x()# 获取柱形图横坐标 可以+/-数值使其居中
        y_text = rec.get_height() + 10# 获取柱子的高度 +0.02
        plt.text(x_text, y_text, data_i[i], fontsize=8)

plt.legend()
plt.savefig('存储代价.pdf')
plt.show()