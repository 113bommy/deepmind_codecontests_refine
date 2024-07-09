import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

n,s = nm()
a = nl()
mod = 998244353
ans = 0
dp = [[0]*(s+1) for i in range(n+1)]
dp[0][0] = 1
for i,v in enumerate(a):
    dp[i+1][0] = 1
    for j in range(s+1):
        dp[i+1][j] += dp[i][j]
        if j >= v: dp[i+1][j] += dp[i][j-v]
        dp[i+1][j] %= mod
    ans += dp[i+1][s]
print(ans%mod)
