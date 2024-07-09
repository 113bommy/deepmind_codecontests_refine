# -*- coding: utf-8 -*-
"""
Created on Fri Jul 13 23:02:50 2018

@author: admin123
"""
h_w = []
N = int(input(''))
for x in range(0,int(N)):
    h_w.append(input('').split(' ')) 
    
max_height = max(int(h_w[0][0]),int(h_w[0][1]))

for n in range(0,N):
    if N==1:
        print('YES')
        break
    n_min_height = min(int(h_w[n][0]),int(h_w[n][1]))
    n_max_height = max(int(h_w[n][0]),int(h_w[n][1]))
    
    if n_min_height > max_height:
        print('NO')
        break
    else:
        if n_max_height <= max_height:
            max_height = n_max_height
        else:
            max_height = n_min_height
 
        if n is  N-1:
            print('YES')

