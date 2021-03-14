import matplotlib.pylab as pyl
import matplotlib.ticker as ticker
import numpy as np
from matplotlib.pyplot import MultipleLocator

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = [0, 0, 0, 0, 4, 20, 30, 42, 49, 55]

x1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y1 = [0, 0, 0, 0, 0, 1, 3, 3, 4, 4.7]

x2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y2 = [0, 0, 0, 0, 0, 0, 0, 0, 0.005, 0.5]

#x3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
#y3 = [36, 32, 30, 27]


pyl.rcParams['font.sans-serif'] = ['SimHei']
ln2 = pyl.plot(x2, y2, color = 'silver', label='实验配置1')

ln = pyl.plot(x, y, color = 'grey', label='实验配置2')
#pyl.scatter(x ,y, color='darkslategray')

ln1 = pyl.plot(x1, y1, color = 'k', label='实验配置3')
#pyl.scatter(x1, y1, color='mediumseagreen')


#pyl.scatter(x2, y2, color='mediumturquoise')

#ln3 = pyl.plot(x3, y3, color = 'lightskyblue', label='cpu核4使用率')
#pyl.scatter(x3, y3, color='lightskyblue')

pyl.legend(loc='best')

pyl.xlim(0,10)
pyl.ylim(0,100)
x_major_locator=MultipleLocator(1)
ax=pyl.gca()
ax.xaxis.set_major_locator(x_major_locator)
pyl.xlabel("流量大小/Gbps")
pyl.ylabel("丢包率/%")

"""
for x,y in zip(x,y):
    pyl.text(x,y + 1,'%.0f' %y,ha = 'center', va= 'bottom',fontsize = 15 )
for x,y in zip(x1,y1):
    pyl.text(x,y + 3,'%.0f' %y,ha = 'center', va= 'bottom',fontsize = 8 )
for x,y in zip(x2,y2):
    pyl.text(x,y + 1,'%.0f' %y,ha = 'center', va= 'bottom',fontsize = 8 )
for x,y in zip(x3,y3):
    pyl.text(x,y + 1,'%.0f' %y,ha = 'center', va= 'bottom',fontsize = 8 )"""
pyl.gca().xaxis.set_major_formatter(ticker.FormatStrFormatter('%d'))
pyl.show()
