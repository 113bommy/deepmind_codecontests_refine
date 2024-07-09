#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n = int(input())
S = input()
s1 = S[:n];s2 = S[n:][::-1]
C1 = collections.Counter()
C2 = collections.Counter()
for bit in range(2**n):
  tmp10 = ""
  tmp11 = ""
  tmp20 = ""
  tmp21 = ""
  for i in range(n):
    if bit >> i & 1:
      tmp10 += s1[i]
      tmp20 += s2[i]
    else:
      tmp11 += s1[i]
      tmp21 += s2[i]
  C1[(tmp10,tmp11)] += 1
  C2[(tmp21,tmp20)] += 1
for key,item in C1.items():
  ans += C2[key] * item 
print(ans)
