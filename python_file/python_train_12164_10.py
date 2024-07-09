# -*- coding: utf-8 -*-
from pprint import pprint
N = int(input())
tn = list(map(int, input().split()))
vn = list(map(int, input().split()))

tn_sum = sum(tn)
time_tbl = [0 for _ in range(tn_sum*2+1)]  # 0.5刻みで×２

lrv = []
lrv.append([0, 0, 0])
t_sum = 0
for t, v in zip(tn, vn):
    lrv.append([t_sum, t_sum+t, v])
    t_sum += t
lrv.append([tn_sum, tn_sum, 0])


def f(l,r,x,v):
    if x <= l:
        return v + l - x
    elif l < x < r:
        return v
    else:
        return v + x - r

for t05 in range(tn_sum*2+1):
    time_tbl[t05] = min([f(l, r, t05/2, v) for l, r, v in lrv])

area = .0
for i in range(tn_sum*2):
    area += (time_tbl[i] + time_tbl[i+1])/4

print(area)
