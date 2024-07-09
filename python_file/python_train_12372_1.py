N=int(input())
A=[list(map(int,input().split())) for i in range(N)]
r=0
for i,aa in enumerate(A):
    for j,a in enumerate(aa[i+1:]):
        f=1
        j+=i+1
        for k in range(N):
            if k==i or k==j:
                continue
            if a>A[i][k]+A[k][j]:
                f=r=-1
                break
            if a==A[i][k]+A[k][j]:
                f=0
                break
        if f==1:
            r+=a
        elif f==-1:
            break
    if r<0:
        break
print(r)