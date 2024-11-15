from collections import defaultdict, deque, Counter
from sys import stdin, stdout
from heapq import heappush, heappop
import math
import io
import os
import math
import bisect

#?############################################################


def isPrime(x):
    for i in range(2, x):
        if i*i > x:
            break
        if (x % i == 0):
            return False
    return True

#?############################################################


def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, p - 2, p)) % p


#?############################################################

def primeFactors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n / 2
    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            l.append(int(i))
            n = n / i
    if n > 2:
        l.append(n)
    return list(set(l))


#?############################################################

def power(x, y, p):
    res = 1
    x = x % p
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

#?############################################################


def sieve(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    return prime


#?############################################################

def digits(n):
    c = 0
    while (n > 0):
        n //= 10
        c += 1
    return c

#?############################################################


def ceil(n, x):
    if (n % x == 0):
        return n//x
    return n//x+1

#?############################################################


def mapin():
    return map(str, input().split())

#?############################################################
def aa(no):
    ans = no.count(0)
        
    if(ans == 1):
        for i in range(26):
            if(no[i] == 0):
                return i
        
        
    return -1
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
# python3 15.py<in>op\
n = int(input())
no = [0]*26
nn = set()
for i in range(26):
    nn.add(chr(i+97))
ans = 0
fl = -1
for i in range(n):
    a, b = mapin()
    if(a == "."):
        for j in b:
            if(j in nn):
                nn.discard(j)
        if(len(nn) == 1):
            fl = nn.pop()
            nn.add(fl) 
    
    elif(a == "!"):
        if(fl == -1):
            ss = set()
            for j in b:
                ss.add(j)
                
            nn = nn.intersection(ss)
            if(len(nn) == 1):
                fl = nn.pop()
                nn.add(fl) 
        else:
            ans+=1
            
    else:
        
        if(b not in nn and fl!=-1):
            ans+=1
        else:
            nn.discard(b)  
            if(len(nn) == 1):
                fl = nn.pop()
                nn.add(fl) 
            
    # print(nn, ans)
print(ans)
            
        