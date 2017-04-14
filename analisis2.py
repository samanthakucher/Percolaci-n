# -*- coding: utf-8 -*-
"""
Created on Fri Apr 14 14:20:01 2017

@author: dran
"""
## CÓDIGO PARA EL PUNTO 1b) 

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