import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

n = ni()
a = nl()
dp = [[0]*3 for _ in range(n+5)]
t = n%2
for i in range(n):
    dp[i][0] = dp[i-2][0] + a[i]
    dp[i][1] = max(dp[i-2][1], dp[i-3][0]) + a[i]
    if t:
        dp[i][2] = max(dp[i-2][2], dp[i-3][1], dp[i-4][0]) + a[i]
if t:
    print(max(dp[n-3][0], dp[n-2][1], dp[n-1][2]))
else:
    print(max(dp[n-2][0], dp[n-1][1]))
