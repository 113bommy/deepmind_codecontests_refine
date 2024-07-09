from collections import *
from functools import reduce
import sys
input = sys.stdin.readline

def factors(n):    
    return set(reduce(list.__add__,([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

def li():return [int(i) for i in input().rstrip('\n').split(' ')]
def st():return input().rstrip('\n')
def val():return int(input())

vect = []
def sieve():
    global vect
    a = [True for i in range(10**5 + 5)]
    for i in range(2,10**5 + 5):
        if a[i]:
            for j in range(2*i,10**5,i):a[j] = False
    for i in range(2,10**5 + 2):
        if a[i]:vect.append(i)

def calculate(a,i):
    j = curr = tot = 0

    while j<len(a):
        tot += abs(curr)
        a[j] += curr
        curr = a[j]%i

        if curr>i/2:
            curr = i - curr
            temp = j+1
            while temp<len(a) and curr:
                tot += curr
                currtemp = min(curr,a[temp])
                curr -= currtemp
                a[temp] -= currtemp

                temp += 1
            j = temp - 1


        j += 1
    # print(tot)
    return tot



n = val()
l = li()

sieve()
# print(l)
temp = sum(l)
do = []
for i in vect:
    if temp%i == 0:
        do.append(i)
ans = 1000000000000000000000000000
temp = l.copy()
# print(l,temp)
for i in do:
    l = temp.copy()
    ans = min(ans,calculate(l,i))
    # print(l,temp,i)

print(ans if ans!=1000000000000000000000000000 else -1)