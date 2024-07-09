n, k = map(int, input().split())
H = list(map(int, input().split()))
dp = [0] * n
for i in range(1, n):
    dp[i] = min(dp[i - j - 1] + abs(H[i] - H[i - j - 1]) for j in range(min(k, i)))

print(dp[n - 1])
