import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
#from bisect import bisect_left as bl, bisect_right as br, insort
#from heapq import heapify, heappush, heappop
#from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
#from fractions import Fraction
#sys.setrecursionlimit(100000)
#INF = float('inf')
mod = 998244353

def is_pallindrome(s):
    cnt=0
    for i in range(len(s)//2):
        if s[i]!=s[~i]:
            cnt+=1
    return cnt

for t in range(int(data())):
    n=int(data())
    s=data()
    a = 0
    for i in s:
        if i=='0':
            a+=1
    cnt = is_pallindrome(s)
    if cnt==0:
        if a%2==0:
            out("BOB")
        else:
            if a==1:
                out("BOB")
            else:
                out("ALICE")
    else:
        if cnt>1:
            out("ALICE")
        else:
            if a == 2:
                out("DRAW")
            else:
                out("ALICE")





