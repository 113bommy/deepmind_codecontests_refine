import sys

inf = float("inf")
# sys.setrecursionlimit(10000000)

# abc='abcdefghijklmnopqrstuvwxyz'
# abd={'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
mod, MOD = 1000000007, 998244353
# vow=['a','e','i','o','u']
# dx,dy=[-1,1,0,0],[0,0,1,-1]

# import random
# from collections import deque, Counter, OrderedDict,defaultdict
# from heapq import nsmallest, nlargest, heapify,heappop ,heappush, heapreplace
# from math import ceil,floor,log,sqrt,factorial
# from bisect import bisect,bisect_left,bisect_right,insort,insort_left,insort_right

def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()

n,k = get_ints()
Arr = get_array()
mini = min(Arr)
maxi = max(Arr)
if maxi>=mini*k +2:
    print('NO')
    exit()
print('YES')
for i in range(n):
    times = Arr[i]
    for i in range(times):
        if i!=times-1:
            print(i%k +1 , end = ' ')
        else:
            print(i%k +1)
