n,m,q=map(int,input().split())
train=[[0]*n for i in range(n)]
for i in range(m):
    l,r=map(int,input().split())
    train[l-1][r-1]+=1
for i in range(n):
    for j in range(n-1):
        train[i][j+1]+=train[i][j]
for i in range(q):
    p,q_=map(int,input().split())
    ans=0
    for j in range(p-1,q_):
        ans+=train[j][q_-1]
    print(ans)

