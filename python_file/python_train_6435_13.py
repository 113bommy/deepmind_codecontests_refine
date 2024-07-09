K = input()
N = len(K)
D = int(input())
mod = 10**9+7

dp = [[[0]*D for _ in range(2)] for _ in range(N+1)]
dp[0][1][0] = 0
dp[0][0][0] = 1

for i in range(N):
    a = ord(K[i])-48
    
    for j in range(D):
        for k in range(10):
            dp[i+1][1][(j+k)%D] += dp[i][1][j]
            dp[i+1][1][(j+k)%D] %= mod

    for j in range(D):
        dp[i+1][0][(j+a)%D] += dp[i][0][j]
        dp[i+1][0][(j+a)%D] %= mod

    for j in range(D):
        for k in range(a):
            dp[i+1][1][(j+k)%D] += dp[i][0][j]
            dp[i+1][1][(j+k)%D] %= mod

print((dp[N][1][0] + dp[N][0][0]-1)%mod)