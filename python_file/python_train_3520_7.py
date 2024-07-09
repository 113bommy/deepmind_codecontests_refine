# coding: utf-8
import itertools
import sys
sys.setrecursionlimit(100000)
input=lambda : sys.stdin.readline().rstrip('\n')

n=int(input())
d=[0]+list(itertools.accumulate(map(int,input().split())))
memo=[[-1 for i in range(401)]for i in range(401)]
def split_slime(l,r):
    if l+1==r:
        return 0
    if memo[l][r]!=-1:
        return memo[l][r]
    mn=10**18
    for i in range(l+1,r):
        cost=(d[i]-d[l])+(d[r]-d[i])+split_slime(l,i)+split_slime(i,r)
        if mn>cost:
            mn=cost
    memo[l][r]=mn
    return memo[l][r]
print(split_slime(0,n))