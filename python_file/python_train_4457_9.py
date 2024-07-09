MOD = 10**9 + 7
n, oddness = [int(item) for item in input().split()]
# Oddness must be even
if oddness % 2 ==  1:
    print(0)
    exit()
oddness //= 2
max_oddness = n*n + n
max_pending = n + 1

dp = [[[0] * (max_oddness) for _ in range(max_pending)] for _ in range(n)]
dp[0][0][0] = 1
dp[0][1][1] = 1
oddness_itr = [item for item in range(n*n)]
for i in range(1, n):
    for j in range(i+1):
        # Too many pending items 
        if j > n // 2:
            break
        for k in oddness_itr:
            # Connect in line
            # Oddness increase by num of pending item
            dp[i][j][k+j] += dp[i-1][j][k]
            # Choose 1 from pending items
            dp[i][j][k+j] += dp[i-1][j][k] * j*2 
            dp[i][j][k+j] %= MOD
            # Choose 2 from pending items
            if j > 0:
                dp[i][j-1][k+j-1] += dp[i-1][j][k] * j*j
                dp[i][j-1][k+j-1] %= MOD 
            # Do nothing 
            dp[i][j+1][k+j+1] += dp[i-1][j][k] 
            dp[i][j+1][k+j+1] %= MOD 

print(dp[n-1][0][oddness])