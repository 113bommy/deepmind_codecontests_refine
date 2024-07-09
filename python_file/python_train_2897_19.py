N=int(input())
S=["" for j in range(N)]
for i in range(N):
    S[i]=input()

ans=0
for i in range(0,N):
    flag=True
    for j in range(0,N):
        for k in range(0,N):
            flag=flag&(S[(k+i)%N][j]==S[(j+i)%N][k])
    ans+=N*int(flag)

print(ans)
