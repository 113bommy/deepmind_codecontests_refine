
N = int(input())
a = list(map(int, input().split()))

dp = [[0] * (N) for _ in range(N+1)]
ans = int(0)
for i in range(N):
    dp[i][i] = a[i]

#for l in range(1,N)
for l in range(1,N):
    for i in range(N-l):
        j = i + l
        dp[i][j] = max(dp[i][i]-dp[i+1][j], dp[j][j]-dp[i][j-1])


ans = dp[0][N-1]

print(ans)
#print(dp)