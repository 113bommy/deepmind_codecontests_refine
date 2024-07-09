N,T = map(int,input().split())
AB = [list(map(int,input().split())) for _ in range(N)]
AB.sort(key=lambda x:x[0])

dp = [[0]*T for i in range(N+1)]
ans = 0
for n in range(N):
    for w in range(T):
        ans = max(ans,dp[n][w]+AB[n][1])
        if w-AB[n][0]>=0:
            dp[n+1][w] = max(dp[n][w],dp[n][w-AB[n][0]]+AB[n][1])
        else:
            dp[n+1][w] = dp[n][w]

print(ans)