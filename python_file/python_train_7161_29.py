n,w = map(int,input().split())
items = sorted([list(map(int,input().split())) for i in range(n)])
dp = [[0]*(w+1) for _ in range(n+2)]
for i in range(n):
    wi, vi = items[i]
    for j in range(w+1):
        if j+wi<=w:
            dp[i+1][j+wi] = max(dp[i+1][j+wi], dp[i][j]+vi)
        dp[i+1][j] = max(dp[i][j], dp[i+1][j])
ans = 0
for i, (wi, vi) in enumerate(items):
    ans = max(ans, dp[i][w-1]+vi)
print(ans)
