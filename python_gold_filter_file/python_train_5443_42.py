# -*- coding: utf-8 -*-
"""
Created on Tue Oct 27 20:34:58 2020

@author: Dark Soul
"""
t=int(input(''))
for _ in range(t):
    [l,r]=list(map(int,input().split()))
    if 2*l>r:
        print('YES')
    else:
        print('NO')