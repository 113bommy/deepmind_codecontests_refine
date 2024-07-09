N,K=map(int,input().split())
XYC=[list(input().split()) for i in range(N)]

MAP=[[0 for i in range(K*2+1)] for j in range(K*2+1)]
mod=K*2
for x,y,c in XYC:
    x=int(x)
    y=int(y)
    if c=="W":
        x+=K

    MAP[x%mod+1][y%mod+1]+=1
    MAP[(x+K)%mod+1][(y+K)%mod+1]+=1




for i in range(K*2+1):
    for j in range(1,K*2+1):
        MAP[i][j]=MAP[i][j-1]+MAP[i][j]

for i in range(K*2+1):
    for j in range(1,K*2+1):
        MAP[j][i]=MAP[j-1][i]+MAP[j][i]

ANS=0
for i in range(K):
    for j in range(K):

        if ANS<MAP[i+K][j+K]-MAP[i][j+K]-MAP[i+K][j]+MAP[i][j]:
            ANS=MAP[i+K][j+K]-MAP[i][j+K]-MAP[i+K][j]+MAP[i][j]
        if ANS<N-(MAP[i+K][j+K]-MAP[i][j+K]-MAP[i+K][j]+MAP[i][j]):
            ANS=N-(MAP[i+K][j+K]-MAP[i][j+K]-MAP[i+K][j]+MAP[i][j])
print(ANS)
