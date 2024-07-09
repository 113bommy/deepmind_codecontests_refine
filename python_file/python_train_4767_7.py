# -*- coding: utf-8 -*-

#############
# Libraries #
#############

import math

#############
# Constants #
#############

MOD = 10**9 +7
INF = float('inf')

#############
# Functions #
#############

kaijo_memo = []
def kaijo(n):
  if(len(kaijo_memo) > n):
    return kaijo_memo[n]
  if(len(kaijo_memo) == 0):
    kaijo_memo.append(1)
  while(len(kaijo_memo) <= n):
    kaijo_memo.append(kaijo_memo[-1] * len(kaijo_memo) % MOD)
  return kaijo_memo[n]

gyaku_kaijo_memo = []
def gyaku_kaijo(n):
  if(len(gyaku_kaijo_memo) > n):
    return gyaku_kaijo_memo[n]
  if(len(gyaku_kaijo_memo) == 0):
    gyaku_kaijo_memo.append(1)
  while(len(gyaku_kaijo_memo) <= n):
    gyaku_kaijo_memo.append(gyaku_kaijo_memo[-1] * pow(len(gyaku_kaijo_memo),MOD-2,MOD) % MOD)
  return gyaku_kaijo_memo[n]

def nCr(n,r):
  if(n == r):
    return 1
  if(n < r or r < 0):
    return 0
  ret = 1
  ret = ret * kaijo(n) % MOD
  ret = ret * gyaku_kaijo(r) % MOD
  ret = ret * gyaku_kaijo(n-r) % MOD
  return ret

#############
# Main Code #
#############

k,q = map(int, input().split())
d = list(map(int, input().split()))

def query(n,x,m):
  x %= m
  ans = n-1
  n -= 1
  s1 = 0
  t1 = 0
  for i in range(k):
    s1 += d[i] % m
    if d[i] % m == 0:
      t1 += 1
  s2 = 0
  t2 = 0
  for i in range(n%k):
    s2 += d[i] % m
    if d[i] % m == 0:
      t2 += 1
  x += s1 * (n//k) + s2
  ans -= x//m
  ans -= t1 * (n//k) + t2
  
  print(ans)
  
    

for _ in range(q):
  n,x,m = map(int, input().split())
  query(n,x,m)
