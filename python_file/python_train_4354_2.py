N = int(input())
a = [int(x) for x in input().split()]

dp = [[[] for _ in range(N)] for _ in range(N)]
for i in range(N):
    dp[i][i] = a[i]

for l in range(1, N):
    for i in range(N-l):
        dp[i][i+l] = max(a[i] - dp[i+1][i+l], a[i+l] - dp[i][i+l-1])

print(dp[0][N-1])