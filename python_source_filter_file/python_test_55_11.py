# This code is contributed by Siddharth


from sys import *
input = stdin.readline



import threading
from bisect import *
import math
from collections import *
import operator
from heapq import *
from itertools import *
inf=10**19
mod=10**9+7
MOD=998244353
S1 = 'abcdefghijklmnopqrstuvwxyz'
S2 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
drow = [0, 1, 0, -1]
dcol = [-1, 0, 1, 0]
# inverse modulo power pow(a,-1,mod) - it only works on py 3.8 ( *not in pypy )
setrecursionlimit(200005)
def asc(c):
    return ord(c)-97+1




# ==========================================> Code Starts Here <=====================================================================)

n=int(input())
ans=6
ans=(ans*(pow(4,pow(2,n,mod)-2,mod)))%mod
print(ans%mod)