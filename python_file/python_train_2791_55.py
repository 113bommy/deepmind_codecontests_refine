N, K = map(int, input().split())
hn = list(map(int, input().split()))

dp = [0]*N
for i in range(1, N):
    dp[i] = min(dp[j]+abs(hn[i]-hn[j]) for j in range(i-1, i-1-K, -1) if j >= 0)
print(dp[-1])
