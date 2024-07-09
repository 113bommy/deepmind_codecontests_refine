N,K = map(int, input().split())
h = list(int(i) for i in input().split())
dp = [float("inf")]*N
dp[0] = 0
for i in range(1,N):
    for j in range(max(0,i-K),i):
        dp[i] = min(dp[i],dp[j]+abs(h[i]-h[j]))
print(dp[-1])