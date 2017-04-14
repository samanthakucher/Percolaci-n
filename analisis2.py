# -*- coding: utf-8 -*-
"""
Created on Fri Apr 14 14:20:01 2017

@author: dran
"""
## PUNTO 1b) 

import numpy as np
import matplotlib.pyplot as plt

Fp16 = np.loadtxt("Fp_16.txt")
Fp4 = np.loadtxt("Fp_4.txt")
Fp32 = np.loadtxt("Fp_32.txt")
Fp64 = np.loadtxt("Fp_64.txt")
Fp128 = np.loadtxt("Fp_128.txt")

p = []
k=0;
for i in range(100):
    p.append(k)    
    k=k+1/np.size(Fp128)
    
plt.plot(p,Fp128,'-ro', linewidth=1.8)
plt.title('F(p).dp para L = 128')
plt.xlabel('p')
plt.ylabel('F(p).dp')
plt.show()
###################################################################

# PUNTO 1c) 
# Las dispersiones las calcula usando las listas de probabilidades del punto 1a) 
# Hay que poner en la carpeta los archivos L4.txt, L16.txt... del punto 1a) !!!
L4 = np.loadtxt("L4.txt")
L16 = np.loadtxt("L16.txt")
L32 = np.loadtxt("L32.txt")
L64 = np.loadtxt("L64.txt")
L128 = np.loadtxt("L128.txt")

# Calcula las varianzas.
std = [ np.std(L4),  np.std(L16),  np.std(L32),  np.std(L64),  np.std(L128)]
L = [4, 16, 32 , 64, 128]  ## tamaños de red

plt.plot(L,std,'-bo', linewidth=1.8)
plt.title('Desviaciones estandar para Pc')
plt.xlabel('p')
plt.ylabel('sigma')
plt.show()

