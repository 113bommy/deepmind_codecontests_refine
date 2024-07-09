from math import *
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(input())
    b=list(input())
    l=[]
    for i in range(n):
        if a[i]!=b[i]:
            l.append(i+1)
            l.append(1)
            l.append(i+1)
    print(len(l))
    for i in range(len(l)):
        print(l[i],end=' ')
    print()
    