s = input()
n = len(s)
mod = 998244353

R = [0] * n
B = [0] * n
for i in range(n):
    if s[i] == '0':
        R[i] = 2
    elif s[i] == '1':
        R[i] = 1
        B[i] = 1
    else:
        B[i] = 2

for i in range(n-1):
    R[i+1] += R[i]
    B[i+1] += B[i]


dp = [[0] * (2*n+10) for _ in range(2*n+10)]

if R[0] > 0:
    dp[0][1] = 1
if B[0] > 0:
    dp[0][0] = 1

for i in range(n-1):
    for r in range(2*n+1):
        if R[i+1] >= r+1:
            dp[i+1][r+1] += dp[i][r]
            dp[i+1][r+1] %= mod
        if i+2-r < 0:
            break
        if B[i+1] >= i+2-r:
            dp[i+1][r] += dp[i][r]
            dp[i+1][r] %= mod

for i in range(n-1, 2*n-1):
    for r in range(2*n+1):
        if R[n-1] >= r+1:
            dp[i + 1][r + 1] += dp[i][r]
            dp[i + 1][r + 1] %= mod
        if i+2-r < 0:
            break
        if B[n-1] >= i+2-r:
            dp[i+1][r] += dp[i][r]
            dp[i+1][r] %= mod

ans = 0
for r in range(2*n+1):
    ans += dp[2*n-1][r]
    ans %= mod

print(ans)