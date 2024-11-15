N, Ma, Mb = map(int, input().split())
abc = [list(map(int, input().split())) for _ in range(N)]

inf = float('inf')
dp = [[[inf] * 401 for _ in range(401)] for _ in range(N + 1)]

dp[0][0][0] = 0

for i in range(N):
    for j in range(401):
        for k in range(401):
            dp[i + 1][j][k] = dp[i][j][k]
            if j - abc[i][0] >= 0 and k - abc[i][1] >= 0:
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - abc[i][0]][k - abc[i][1]] + abc[i][2])
ans = inf
for a in range(1, 401):
    for b in range(1, 401):
        if a * Mb == b * Ma:
            ans = min(ans, dp[N][a][b])
if ans == inf:
    ans = -1
print(ans)
