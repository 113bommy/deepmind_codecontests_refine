from sys import maxsize, stdout, stdin,stderr
mod = int(1e9+7)
import sys
def I(): return int(stdin.readline())
def lint(): return [int(x) for x in stdin.readline().split()]
def S(): return list(map(str,input().strip()))
def grid(r, c): return [lint() for i in range(r)]
from collections import defaultdict, Counter, deque
import math
import heapq
from heapq import heappop , heappush
import bisect
from itertools import groupby
from itertools import permutations as comb
def gcd(a,b): 
    while b:
        a %= b
        tmp = a
        a = b
        b = tmp
    
    return a
 
def lcm(a,b): 
    return a  // gcd(a, b) * b
 
def check_prime(n):
    for i in range(2, int(n ** (1 / 2)) + 1):
        if not n % i:
            return False
    return True

def nCr(n, r):
 
    return (fact(n) // (fact(r)
                * fact(n - r)))
 
# Returns factorial of n
def fact(n):
 
    res = 1
     
    for i in range(2, n+1):
        res = res * i
         
    return res
def primefactors(n):
    num=0
    
    while n % 2 == 0:
        num+=1
        n = n / 2
    
    for i in range(3,int(math.sqrt(n))+1,2):
         
    
        while n % i== 0:
            num+=1
            n = n // i
               
    
    if n > 2:
        num+=1
    return num
'''
def iter_ds(src):
    store=[src]
    while len(store):
        tmp=store.pop()
        if not vis[tmp]:
            vis[tmp]=True
            for j in ar[tmp]:
                store.append(j)
'''
def ask(a):
    print('? {}'.format(a),flush=True)
    n=I()
    
    return n


 
def dfs(i,p,d):
    
    a,tmp=0,0
    for j in d[i]:
        if j!=p:
            a+=1
            tmp+=dfs(j,i)
    
    if a==0:
        return 0
    
    return tmp/a + 1 
def primeFactors(n):
    l=[]
    
    while n % 2 == 0:
        l.append(2)
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
         
        
        while n % i== 0:
            l.append(i)
            n = n // i

    if n > 2:
        l.append(n)
    return l
from math import inf


t = I()
for _ in range(t):
    n = I()
    s = lint()
    ans=0
    for i in range(0,n,2):

        ans+=s[i]
    tmp=0
    m=0
    for i in range(0,n-1,2):
        tmp+=s[i+1]-s[i]
        tmp=max(0,tmp)
        m=max(tmp,m)
    tmp=0
    for i in range(1,n-1,2):
        tmp+=s[i+1]-s[i]
        tmp=max(0,tmp)
        m=max(tmp,m)
    m=max(tmp,m)
    print(ans+m)




    