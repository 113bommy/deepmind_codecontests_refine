n,s=int(input()),0
for i in range(1,n+1):
    p,q=(int(x) for x in input().split())
    if (p<q-2):
        s+=1
print(s)
