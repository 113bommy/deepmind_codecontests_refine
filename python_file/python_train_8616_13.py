#!/usr/local/bin/python3

'''
Author: andyli
Time: 2020-06-24 21:10:25
'''

mod = 10**9 + 7

m = int(input())
n = len(input())
t = n+m

fac = [0]*(t+1)
ifac = [0]*(t+1)
pw = [0] * (t+1)
fac[0] = 1
for i in range(1, t+1):
    fac[i] = fac[i-1] * i % mod
ifac[t] = pow(fac[t], mod-2, mod)

for i in range(t-1, -1, -1):
    ifac[i] = ifac[i+1] * (i+1) % mod

pw[0] = 1
for i in range(1, t+1):
    pw[i] = pw[i-1] * 25 % mod

def C(n, m):
    return fac[n]*ifac[m]*ifac[n-m]%mod

ans=0
for i in range(n, t+1):
    ans = (ans + pw[t-i] * C(t, i)) % mod

print(ans)