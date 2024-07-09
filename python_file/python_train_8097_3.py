def divisors(M):#Mの約数列 O(n^(0.5+e))
    import math
    d=[]
    i=1
    while math.sqrt(M)>=i:
        if M%i==0:
            d.append(i)
            if i**2!=M:
                d.append(M//i)
        i=i+1
    d.sort()
    return d

N=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
A=[a[i]^a[i-1] for i in range(0,N)]
B=[b[i]^b[i-1] for i in range(0,N)]
d=divisors(N)
perioda=N
for i in range(0,len(d)):
    test=[A[(j+d[i])%N] for j in range(0,N)]
    if test==A:
        perioda=min(perioda,d[i])

periodb=N
for i in range(0,len(d)):
    test=[B[(j+d[i])%N] for j in range(0,N)]
    if test==B:
        periodb=min(periodb,d[i])

if perioda==periodb:
    A=A[:perioda]
    B=B[:periodb]
    kouho=[]
    for i in range(0,len(B)):
        if A[i]==B[0]:
            kouho.append(i)
    ans=-1
    for i in range(0,len(kouho)):
        test=[A[(j+kouho[i])%perioda] for j in range(0,perioda)]
        if test==B:
            ans=kouho[i]
            break
    if ans!=-1:
        for i in range(0,N//perioda):
            print(ans+perioda*i,a[ans+perioda*i]^b[0])