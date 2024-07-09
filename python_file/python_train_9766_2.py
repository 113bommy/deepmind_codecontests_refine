# -*- coding: utf-8 -*-
"""
Created on Sat Mar 30 22:26:37 2019

@author: Owner
"""

MOD = 1000000007

def inv(x):
    return pow(x, MOD - 2, MOD)

B, W = map(int, input().split())
fct = [1] * (B + W + 1)
for i in range(B + W):
    fct[i + 1] = (fct[i] * (i + 1)) % MOD

def c(n, k):
    return (fct[n] * inv(fct[k]) * inv(fct[n - k])) % MOD

#p[i]: 黒B回白i回の確率
#q[i]: 黒i回白W回の確率
p = [0] * W
p[0] = inv(pow(2, B, MOD))
for i in range(W - 1):
    p[i + 1] = (p[i] + c(B + i, i + 1) * inv(pow(2, B + i, MOD)) * inv(2)) % MOD
q = [0] * B
q[0] = inv(pow(2, W, MOD))
for i in range(B - 1):
    q[i + 1] = (q[i] + c(W + i, i + 1) * inv(pow(2, W + i, MOD)) * inv(2)) % MOD
for i in range(B + W):
    if i < min(B, W):
        print(inv(2))
        continue
    if i >= max(B, W):
        print((q[i - W] + (1 - p[i - B] - q[i - W] + MOD) * inv(2)) % MOD)
        continue
    if B < W:
        print(((1 - p[i - B] + MOD) * inv(2)) % MOD)
    else:
        print((q[i - W] + (1 - q[i - W] + MOD) * inv(2)) % MOD)