import numpy as np
import statistics as st
from matplotlib import pyplot as plt

L4 = np.loadtxt("L4.txt")
L16 = np.loadtxt("L16.txt")
L32 = np.loadtxt("L32.txt")
L64 = np.loadtxt("L64.txt")
L128 = np.loadtxt("L128.txt")

#1)a)
Prom_4 = np.mean(L4)
Prom_16 = np.mean(L16)
Prom_32 = np.mean(L32)
Prom_64 = np.mean(L64)
Prom_128 = np.mean(L128)
Pc_prom = [Prom_4, Prom_16, Prom_32, Prom_64, Prom_128]

Med_4 = np.median(L4)
Med_16 = np.median(L16)
Med_32 = np.median(L32)
Med_64 = np.median(L64)
Med_128 = np.median(L128)
Pc_med = [Med_4, Med_16, Med_32, Med_64, Med_128]


'''
#1)b)
#Ponele que pi=i/#iteraciones asi estan equiespaciados
datoshist = np.loadtxt("datoshist.txt") #Cantidad de veces que percoló para cada p

plt.hist(datoshist[:,1], 1/len(datoshist[:,0]), range=[0,1], color = 'c', alpha=0.5)
plt.title('Histograma')
plt.draw()
plt.show()
'''
#1)c)
'''
def suma(vector, prom):
    suma=0
    for i in range(0,len(vector)):
        suma=suma+(vector[i] - prom)**2
    return suma

sigma_4 = np.sqrt(suma(L4,Prom_4)/len(L4))
sigma_16 = np.sqrt(suma(L16,Prom_16)/len(L16))
sigma_32 = np.sqrt(suma(L32,Prom_32)/len(L32))
sigma_64 = np.sqrt(suma(L64,Prom_64)/len(L64))
sigma_128 = np.sqrt(suma(L128,Prom_128)/len(L128))
'''
sigma_4 = st.pstdev(L4)
sigma_16 = st.pstdev(L16)
sigma_32 = st.pstdev(L32)
sigma_64 = st.pstdev(L64)
sigma_128 = st.pstdev(L128)
sigmas = [sigma_4, sigma_16, sigma_32, sigma_64, sigma_128]

plt.plot(sigmas, Pc_prom, 'g-') #Pc(inf) es la ordenada al origen. Vamos a tener que tomar mas puntos.
plt.xlabel('Sigma')
plt.ylabel('Pc(L)')
