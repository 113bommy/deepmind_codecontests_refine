N,C = map(int,input().split())
DP = [[0]*C for i in range(10**5+1)]
for i in range(N):
    s,t,c = map(int,input().split())
    DP[s][c-1] = t-s+1
ans = 0
for i in range(10**5):
    hoge = 0
    for j in range(C):
        DP[i+1][j] = max(DP[i][j]-1,DP[i+1][j])
        if DP[i][j]: hoge += 1
    ans = max(ans,hoge)

print(ans)
