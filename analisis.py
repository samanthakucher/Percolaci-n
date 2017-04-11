import numpy as np
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

#1)b)
#Me parce que no es esto.
#Deberiamos agarrar una probabilidad y repetir varias veces y guardar otro txt que diga si percolò o no para esa probabilidad y hacer histograma
Med_4 = np.median(L4)
Med_16 = np.median(L16)
Med_32 = np.median(L32)
Med_64 = np.median(L64)
Med_128 = np.median(L128)


#1)c) 
def suma(vector, prom):
	suma=0
    for i in range(0,len(vector)):
        suma=suma+(vector[i] - prom)**2
	return suma

sigma_4 = sqrt(suma(L4,Pc_4)/len(L4)) 
sigma_16 = sqrt(suma(L16,Pc_16)/len(L16)) 
sigma_32 = sqrt(suma(L32,Pc_32)/len(L32)) 
sigma_64 = sqrt(suma(L64,Pc_64)/len(L64)) 
sigma_128 = sqrt(suma(L128,Pc_128)/len(L128)) 

sigmas = [sigma_4, sigma_16, sigma_32, sigma_64, sigma_128]

plt.plot(sigmas, Pc_prom, 'g-') #Pc(inf) es la ordenada al origen. Vamos a tener que tomar mas puntos.
plt.xlabel('Sigma')
plt.ylabel('Pc(L)')

