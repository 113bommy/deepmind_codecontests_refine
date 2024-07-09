import sys
input = sys.stdin.readline
import bisect

#1st way
for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = sorted(a)
    d = [0]*(n+1)
    #print(a, b)
    for i in a:
        d[b.index(i)] = 1 + max(d[b.index(i)],d[b.index(i)-1])
        #print(d)
    print(n-max(d))