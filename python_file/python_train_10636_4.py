# -*- coding: utf-8 -*-
"""
@author: souradeep1999 

"""
#solution with out using string STL
#use pypy to handle overflow :P
import math as ma

def num():
    return map(int , input().split())
def nu():
    return int(input())
def li():
    return input().split()
def lli (): 
    return list (map (int, input ().split ()))
def fli():
    return [float(x) for x in input().split()]

def FindLen(num):
    c = 0
    while num > 0:
        c += 1
        num //= 10
    return c
        

row,col = (42,42)
x = [[0] * col] * row
y = [[0] * col] * row
MOD = 998244353
p = [10 ** i for i in range(21)]
f = [0] * 18

n = nu()
a = lli()
for i in range(n):
    l = FindLen(a[i])
    f[l] += 1
for i in range(n):
    l = FindLen(a[i])
    if l == 1:
        y[1][0] = (y[1][0] + a[i]) % MOD
    next_add = 0
    pre = a[i] % 10
    for j in range(1,l + 1):
        val = a[i] // p[j -1]
        val = (val * p[2 * j - 1])
        val += next_add;            
        next_add = val % p[2 * j]
        val %= MOD
        x[l][j] += val
        x[l][j] %= MOD
        
        if j == l:
            break
        
        val = a[i] // p[j];
        val = (val * p[2 * j])
        val = (val + pre) 
        pre = val % p[2 * j + 1]
        val %= MOD
        y[l][j] += val
        y[l][j] %= MOD

ans = 0
for i in range(1,11):
    if f[i] > 0:
        for j in range(1,i):
            if f[j] > 0:
                ans += (f[j] * x[i][j] + f[i] * y[j][j - 1]) % MOD
                ans %= MOD
        ans += (f[i] * (x[i][i] + y[i][i - 1]) % MOD) % MOD
        ans %= MOD
        for j in range(i + 1,11):
            if f[j] > 0:
                ans += ((f[i] * y[j][i]) % MOD + (f[j] * x[i][i]) % MOD) % MOD
                ans %= MOD
print(ans)

