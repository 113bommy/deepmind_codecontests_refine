N=int(input())
S=[input() for i in range(N)]
ans=0
for k in range(N):
    flag=1
    for i in range(N):
        for j in range(N):
            if S[(i+k)%N][j]!=S[(j+k)%N][i]:
                flag=0
                break
        if flag==0:
            break
    if flag==1:
        ans+=N
print(ans)
