import sys,math,bisect
from random import randint
inf = float('inf')
mod = 10**9+7
"========================================"
def lcm(a,b):
    return int((a/math.gcd(a,b))*b)
def gcd(a,b):
    return int(math.gcd(a,b))
def tobinary(n):
    return bin(n)[2:]
def binarySearch(a,x):
    i = bisect.bisect_left(a,x)
    if i!=len(a) and a[i]==x:
        return i
    else:
        return -1
def lowerBound(a, x):
    i = bisect.bisect_left(a, x)
    if i:
        return (i-1)
    else:
        return -1
def upperBound(a,x):
    i = bisect.bisect_right(a,x)
    if i!= len(a)+1 and a[i-1]==x:
        return (i-1)
    else:
        return -1
def primesInRange(n):
    ans = []
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    for p in range(2, n+1):
        if prime[p]:
            ans.append(p)
    return ans
def primeFactors(n):
    factors = []
    while n % 2 == 0:
        factors.append(2)
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            factors.append(i)
            n = n // i
    if n > 2:
        factors.append(n)
    return factors
def isPrime(n,k=5):
    if (n <2):
        return True
    for i in range(0,k):
        a = randint(1,n-1)
        if(pow(a,n-1,n)!=1):
            return False
    return True
"========================================="
"""
n = int(input())
n,k = map(int,input().split())
arr = list(map(int,input().split()))
"""
from collections import deque,defaultdict,Counter
from heapq import heappush, heappop,heapify
import string

n,m=map(int,input().split())
graph = {i:[] for i in range(1,n+1)}
for _ in range(m):
    i=list(map(int,input().split()))
    graph[i[0]].append(i[1])
    graph[i[1]].append(i[0])
cc = []
visited=set()

def dfs(v,visited,cc):
    visited.add(v)
    cc.append(v)
    for node in graph:
        if node not in visited:
            dfs(node,visited,cc)
for i in range(1,n+1):
    stack=[]
    if i not in visited:
        dfs(i,visited,stack)
        cc.append(stack)
ans=1
for i in cc:
    ans*= (2**(len(i)-1))
print(ans)
