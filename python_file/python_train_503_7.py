N, A, *x = map(int, open(0).read().split())
dp = [[[0]*(3000) for _ in range(55)] for _ in range(55)]
dp[0][0][0] = 1

for j in range(N+1):
    for k in range(N+1):
        for s in range(N*A+1):
            if j >= 1:
                dp[j][k][s] += dp[j-1][k][s]  # 選ばない場合
                if k >= 1 and s >= x[j-1]:
                    dp[j][k][s] += dp[j-1][k-1][s-x[j-1]]  # 選ぶ場合
ans = 0
for k in range(1, N+1):
    ans += dp[N][k][k*A]
print(ans)