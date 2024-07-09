N, K = map(int, input().split())
h = list(map(int, input().split()))
dp = [float('inf')]* N
dp[0] = 0
for j in range(1, N):
    for i in range(max(0, j-K), j):
        dp[j] = min(dp[i]+abs(h[j]-h[i]), dp[j])
print(dp[-1])