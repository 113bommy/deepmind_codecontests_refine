n,m,q=map(int,input().split())
S=[[0 for i in range(n+1)] for j in range(n+1)]
for i in range(m):
    l,r=map(int,input().split())
    S[l][r]+=1

for i in range(1,n+1):
    for j in range(1,n):
        S[i][j+1]+=S[i][j]

for i in range(q):
    a,b=map(int,input().split())
    ans=0
    for y in range(a,b+1):
        ans+=S[y][b]-S[y][a-1]
    print(ans)
