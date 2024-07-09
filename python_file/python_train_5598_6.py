# coding: utf-8
import sys

# from operator import itemgetter
sysread = sys.stdin.buffer.readline
read = sys.stdin.buffer.read
printout = sys.stdout.write
sprint = sys.stdout.flush
#from heapq import heappop, heappush
#from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
import math
# from itertools import product, accumulate, combinations, product
#import bisect
# import numpy as np
# from copy import deepcopy
#from collections import deque
# from decimal import Decimal
# from numba import jit

INF = 1 << 50
EPS = 1e-8
mod = 998244353


def intread():
    return int(sysread())
def mapline(t=int):
    return map(t, sysread().split())
def mapread(t=int):
    return map(t, read().split())


class lazy_segtree:
    '''init_val : i-indexed (init_val[0] = self.bin[1])'''
    def __init__(self, n, mod, init = 0, init_val=None):
        self.n = n
        self.init = init
        self.k = math.ceil(math.log2(n))
        self.add_val = 1 << self.k
        self.lazy = [INF] * (1 << (self.k + 1))
        self.bins = [self.init] * (1 << (self.k + 1))
        if init_val != None:
            self.update_set(init_val)
        self.mod = mod

        self.build()
        self.bases = self.bins.copy()

    def __getitem__(self, idx):  # return idx-value
        return self.bins[idx]

    def __setitem__(self, idx, val):
        self.bins[idx] = val

    def update_set(self, vals):
        for idx, i in enumerate(range(self.add_val, self.add_val * 2)):
            if len(vals) > idx:
                self[i] = vals[idx]
            else:continue

    def _func(self, k):
        def f(x):
            return k
        return f

    def fx(self, l, r):
        return (l + r) % self.mod

    def build(self):
        '''cliculate segtree (after update_set)'''
        for i in range(self.add_val - 1, 0 , -1):
            self[i] = self.fx(self[2*i], self[2*i+1])

    def eval(self, idx):
        '''update lazies'''
        if self.lazy[idx] == INF:
            return
        if idx < self.add_val:
            self.lazy[idx * 2 + 1] = self.lazy[idx]
            self.lazy[idx * 2] = self.lazy[idx]
        self[idx] = self.lazy[idx] * self.bases[idx]
        self.lazy[idx] = INF

    def update(self, a, b, x):
        '''[a, b) -> f_x(.)'''
        self._update(a, b, x, 1, 0, self.add_val)

    def _update(self, a, b, x, k, l, r):
        '''update, Recursive from head'''
        self.eval(k)
        if a <= l and b >= r:
            self.lazy[k] = self._func(x)(self.lazy[k])
            self.eval(k)
        elif a < r and l < b:
            self._update(a, b, x, 2 * k, l, (l + r) // 2)
            self._update(a, b, x, 2 * k + 1, (l + r) // 2, r)
            self[k] = self.fx(self[2 * k], self[2 * k + 1])


    def query(self, a, b):
        '''区間値[a, b)'''
        return self.query_sub(a, b, 1, 0, self.add_val)

    def query_sub(self, a, b, k, l, r):
        '''self.bin[k] = [l, r) 内での[a,b]の区間値'''
        self.eval(k)
        if r <= a or b <= l:
            return INF
        elif a <= l and b >= r:
            return self[k]
        else:
            vl = self.query_sub(a, b, k * 2, l, (l+r) // 2)
            vr = self.query_sub(a, b, k * 2 + 1, (l+r) // 2, r)
            return self.fx(vl, vr)

def get_powmod(x, k, mod):
    ret = [1]
    v = 1
    for i in range(k):
        v *= x
        v %= mod
        ret.append(v)
    return ret

def run():
    N, Q = mapline()
    A = get_powmod(10, N-1, mod)[::-1]
    #print(A)
    lst = lazy_segtree(N, mod, init_val = A)
    #print(lst.bins)
    for _ in range(Q):
        l, r, d = mapline()
        l -= 1
        r -= 1
        lst.update(l, r + 1, d)
        #print(lst.lazy)
        print(lst[1])

if __name__ == "__main__":
    run()
