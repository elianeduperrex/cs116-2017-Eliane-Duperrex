import numpy as np
import matplotlib.pyplot as pl
from matplotlib.gridspec import GridSpec

data = np.genfromtxt('../res/times_spike.txt')
select= np.array([d for d in data if d[1] < 30])
data1= select.transpose()

fig = pl.figure()
#gs = gridspec.GridSpec(1,2, heigths_ratios=[4,1])
#fig.subplots_adjust(top=0.9)
 
#pl.figure(1)
gs = GridSpec(4,1)
ax0 = pl.subplot(gs[:-1, :])
ax0.scatter(data1[0],data1[1],alpha=0.8, edgecolors='black', color='grey');
pl.axis([100, 300, 0, 30])
pl.title('neurons that spiked', fontsize=16, color='black', fontstyle='italic')
pl.ylabel('neuron number', color='grey')
ax = pl.gca()
ax.set_xticklabels([])
ax.set_yticklabels([])

pl.subplots_adjust(hspace=0.0)
ax1 = pl.subplot(gs[-1, :])
n, bins, patches = pl.hist(data1[0], 50, normed=0, alpha=0.75, color='grey')
pl.axis([100, 300, 0, 30])
pl.ylabel('frequency', color = 'grey')
pl.xlabel('time [ms]', color = 'grey')

pl.show();



