'''
研究室PCでの解答
'''
import math
#import numpy as np
import queue
import bisect
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)
mod = 10**9+7
dir = [(-1,0),(1,0),(0,-1),(0,1)]
alp = "abcdefghijklmnopqrstuvwxyz"

def main():
    n = int(ipt())
    ans = 0
    a = [int(i) for i in ipt().split()]
    pl = [-1]*(n+1)
    for i,ai in enumerate(a):
        pl[ai] = i+1

    #Bit_Indexed_Tree
    #A1 ... AnのBIT(1-indexed)
    BIT = [0]*(n+1)

    #A1 ~ Aiまでの和 O(logN)
    def BIT_query(idx):
        res_sum = 0
        while idx > 0:
            res_sum += BIT[idx]
            idx -= idx&(-idx)
        return res_sum

    #Ai += x O(logN)
    def BIT_update(idx,x):
        while idx <= n:
            BIT[idx] += x
            idx += idx&(-idx)
        return

    for i in range(1,n+1):
        pi = pl[i]
        ll = 0
        lr = pi
        bi = BIT_query(pl[i])
        while ll != lr:
            mid = ll+(lr-ll)//2
            if BIT_query(mid) == bi:
                lr = mid
            else:
                ll = mid+1
        rl = pi
        rr = n
        while rl != rr:
            mid = rl+(rr-rl+1)//2
            if BIT_query(mid) == bi:
                rl = mid
            else:
                rr = mid-1
#        print("a",rl,lr)
        ans += (pi-lr)*(rl-pi+1)*i
        BIT_update(pi,1)

    print(ans)

    return None

if __name__ == '__main__':
    main()
