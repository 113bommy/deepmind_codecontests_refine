mod = 10**9 + 7

K = input()
D = int(input())

N = len(K)

dp = [[[0]*2 for _ in range(D)] for _ in range(N+1)]
dp[0][0][0] = 1

for i in range(1,N+1):
    for j in range(D):
        dp[i][(j+int(K[i-1])) % D][0] += dp[i-1][j][0]
        for k in range(int(K[i-1])):
            dp[i][(j+k) % D][1] += dp[i-1][j][0]
        for k in range(10):
            dp[i][(j+k) % D][1] += dp[i-1][j][1]
        
        dp[i][j][0] %= mod
        dp[i][j][1] %= mod

ans = (dp[N][0][0] + dp[N][0][1] - 1) % mod
print(ans)