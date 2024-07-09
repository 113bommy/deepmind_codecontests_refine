N=int(input())
A=[[int(i) for i in input().split()] for i in range(N)]
ans=0
for i in range(N):
    for j in range(i+1,N):
        flag=True
        for k in range(N):
            if j==k or i==k:
                continue
            if A[i][j]>A[i][k]+A[k][j]:
                print(-1)
                exit()
            if A[i][j]==A[i][k]+A[k][j]:
                flag=False
        if flag:
            ans+=A[i][j]
print(ans)
