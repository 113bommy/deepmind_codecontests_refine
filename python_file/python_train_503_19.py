N, A = map(int,input().split())
x = list(map(int,input().split()))

dp = [[[0]*(max(sum(x),N*A)+1) for k in range(N+1)] for l in range(N+1)]
# dp[i][j][k] := i番目まででj枚選んで和がkになる組み合わせの数
dp[0][0][0] = 1

for i in range(N):
    for j in range(N):
        for k in range(sum(x)+1):
            dp[i+1][j][k] += dp[i][j][k]
            if k-x[i] >= 0:
                dp[i+1][j+1][k] += dp[i][j][k-x[i]]

ans = 0
for k in range(1,N+1):
    ans += dp[N][k][A*k]
print(ans)
