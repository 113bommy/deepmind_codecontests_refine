import io, os
import sys
input=sys.stdin.readline
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    if n>=k:
        if k==0 and n&1:
            print(1)
        else:
            print(0)
    else:
        print(k-n)
