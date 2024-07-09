# -*- coding: utf-8 -*-
"""
Created on Sat Jun 29 22:14:02 2019

@author: Yamazaki Kenichi
"""

N, K = map(int,input().split())
mod = 10**9+7

r = int(pow(N,1/2))

const = []
if N // r == r:
    s = r - 1
else:
    s = r

for i in range(1,r+1):
    const.append(N//i - N//(i+1))
#if r == int(pow(N,1/2)) :
#    const += [1]
const.reverse()
const = [1 for i in range(s)] + const

dp = [[]]
for c in const:
    try:
        dp[0].append(dp[0][-1] +c)
    except:
        dp[0].append(c)
dp += [[0 for i in range(len(const))] for k in range(K-1)]

for k in range(1,K):
    for i in range(len(const)):
        dp[k][i] = (dp[k][i-1] + dp[k-1][len(const)-i-1]%mod
                      * const[i])%mod
print(dp[-1][-1]%mod)
