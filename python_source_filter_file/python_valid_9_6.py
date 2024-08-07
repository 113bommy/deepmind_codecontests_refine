'''
                ___                       ____                     
  ____ _____ _____/ (_)_  ______  ____ _____/ / /_  __  ______ ___  __
 / __ `/ __ `/ __  / / / / / __ \/ __ `/ __  / __ \/ / / / __ `/ / / /
/ /_/ / /_/ / /_/ / / /_/ / /_/ / /_/ / /_/ / / / / /_/ / /_/ / /_/ / 
\__,_/\__,_/\__,_/_/\__,_/ .___/\__,_/\__,_/_/ /_/\__, /\__,_/\__, /  
                        /_/                      /____/      /____/   
'''
import os.path
from math import gcd, floor, ceil
from collections import *
import sys
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

# joined late


def solve():
    s = st()
    d = Counter(s)
    ans = 0
    odd = 0
    for i in d:
        ans += (d[i]>1)
        odd += d[i] % 2
    ans += odd//2
    pr(ans)


for _ in range(inp()):
    solve()
