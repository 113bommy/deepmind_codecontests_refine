n = int(input())
a = list(map(int, input().split()))
dp = [[0] * n for _ in range(n)]

for i in range(n):
    dp[i][i] = a[i]
for l in range(1, n):
    for s in range(n - l):
        dp[s][s + l] = max(a[s] - dp[s + 1][s + l], a[s + l] - dp[s][s + l - 1])
print(dp[0][n - 1])