import sys
input = sys.stdin.readline
from collections import *

def compress(l):
    l = list(set(l))
    l.sort()
    idx = defaultdict(int)

    for i in range(len(l)):
        idx[l[i]] = i
    
    return idx

t = int(input())

for _ in range(t):
    N = int(input())
    a = list(map(int, input().split()))
    m = compress(a)
    
    for i in range(N):
        a[i] = m[a[i]]+1
    
    idx = defaultdict(int)
    
    for i in range(N):
        idx[a[i]] = i
    
    dp = [0]*N
 
    for i in range(N):
        if a[i]==1:
            dp[i] = 1
        else:
            dp[i] = dp[idx[a[i]-1]]+1
    
    print(N-max(dp))
