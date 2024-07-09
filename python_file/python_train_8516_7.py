def examA():
    N = I()
    ans = 0
    print(ans)
    return

def examB():
    ans = 0
    print(ans)
    return

def examC():
    N = I()
    S = SI()
    Q = I()
    K = LI()
    ans = []
    for k in K:
        D = 0; M = 0; C = 0
        now = 0
        for i in range(N):
            s = S[i]
            if s == "D":
                D += 1
            elif s == "M":
                M += 1
                now += D
            elif s == "C":
                C += now
            if i>=k-1:
                if S[i-k+1] == "D":
                    D -= 1
                    now -= M
                elif S[i-k+1] == "M":
                    M -= 1
#        print(D, M, C)
#        ans.append(C)
        print(C)
#    for v in ans:
#        print(v)
    return

def examD():
    ans = 0
    print(ans)
    return

def examE():
    ans = 0
    print(ans)
    return

import sys,copy,bisect,itertools,heapq,math,random
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet,_ep
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18
_ep = 10**(-12)
alphabet = [chr(ord('a') + i) for i in range(26)]

if __name__ == '__main__':
    examC()

"""

"""