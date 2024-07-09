N,K=map(int,input().split())
A=list(map(int,input().split()))
a=[0]*(N+1)
for i in range(N):
    a[i+1]=a[i]+A[i]
from itertools import combinations
S=[a[r]-a[l] for l,r in combinations(range(N+1),2)]
x,y=0,1<<39
for i in range(40):
    n=0
    for s in S:
        if (x+y)&s==x+y:
            n+=1
    if n>=K:
        x+=y
    y>>=1
print(x)