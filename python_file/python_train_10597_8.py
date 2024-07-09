n, m = map(int, input().split())

dp = [float("inf")] * ((1<<n) + 1)
dp[0] = 0

for i in range(m):
    a, b = map(int, input().split())
    c_list = list(map(int, input().split()))
    c = 0
    for j in range(b):
        c += 1 << (c_list[j]-1)

    for j in range(1<<n):
        dp[j | c] = min(dp[j] + a, dp[j | c])

if dp[(1<<n) - 1] == float("inf"):
    ans = -1
else:
    ans = dp[(1<<n) - 1]

print(ans)
