import math
#import numpy as np
import queue
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)

def main():
    n,k = map(int,ipt().split())
    a = list(map(int,ipt().split()))
#    n = 2*10**5
#    k = 2*10**5
#    a = [i+1 for i in range(n)]
    nxt = [-1]*(n)
    pa = [-1]*(2*10**5+1)
    for i,ai in enumerate(a*2):
        pai = pa[ai]
        if pai == -2:
            continue
        if pai == -1:
            pa[ai] = i
        else:
            nxt[pai] = i-pai+1
            if i <= n-1:
                pa[ai] = i
            else:
                pa[ai] = -2
    dbl = [nxt]
    ni = 1
    while ni <= n*k:
        nnxt = [0]*n
        pnxt = dbl[-1]
        for i in range(n):
            nnxt[i] = pnxt[i]+pnxt[(i+pnxt[i])%n]
        dbl.append(nnxt)
        if min(nnxt) > n*k:
            break
        ni *= 2
    np = 0
    ld = len(dbl)
    ni = len(dbl)-1
#    print(dbl)
    for db in dbl[::-1]:
        while True:
            if db[np%n] < n*k-1-np:
                np += db[np%n]
            else:
                break
#        print(np)
    ans = []
    np %= n
    while np < n:
        if nxt[np]+np > n:
            ans.append(a[np])
            np += 1
        elif nxt[np]+np == n:
            np = n
        else:
            np = nxt[np]+np
    print(" ".join(map(str,ans)))



    return

if __name__ == '__main__':
    main()
