N=int(input())
A=list(map(int,input().split()))
d=[[0]*(N+1) for i in range(N+1)]
for w in range(1,N+1):
    if w%2==N%2:
        for l in range(N+1-w):
            d[l][l+w]=max(d[l][l+w-1]+A[l+w-1],d[l+1][l+w]+A[l])
    else:
        for l in range(N+1-w):
            d[l][l+w]=min(d[l][l+w-1]-A[l+w-1],d[l+1][l+w]-A[l])
print(d[0][N])