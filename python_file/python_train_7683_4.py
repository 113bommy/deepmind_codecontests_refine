#!/usr/bin/env python3
from itertools import combinations
import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
MOD = 10**9 + 7

n = int(input())
cost = []
for i in range(n):
    cost.append([int(item) for item in input().split()])
score = [0] * 2**n
for i in range(1, 2**n):
    lsb = i & -i
    index = lsb.bit_length() - 1
    other = i ^ lsb
    diff = 0
    for j in range(n):
        if other & 1 << j:
            diff += cost[index][j]
    score[i] = score[other] + diff

memo = [-1] * 2**n
memo[0] = 0
for i in range(n):
    memo[1<<i] = 0

def dfs(st):
    if memo[st] != -1:
        return memo[st]
    sst = st
    val = score[st] 
    while True:
        sst = (sst - 1) & st
        if sst == 0:
            break
        val = max(val, dfs(sst) + dfs(sst ^ st))
    memo[st] = val
    return val

ret = dfs(2**n - 1)
print(ret)