n = int(input())
s = str(input())

dp = [[0] * (n+1) for _ in range(n+1)]
ans = 0

for i in range(n):
    for j in range(i,n):
        if s[i] == s[j]:
            dp[i+1][j+1] = dp[i][j] + 1
            ans = max(ans, min(j-i, dp[i+1][j+1]))

print(ans)
