n, m = [int(item) for item in input().split()]
INF = 10 ** 10
dp = [INF] * (2 ** n)
dp[0] = 0
for i in range(m):
    a, b = [int(item) for item in  input().split()]
    c = [int(item) - 1 for item in  input().split()]
    bit = 0
    for item in c:
        bit |= 1 << item
    for j in range(2 ** n):
        dp[j | bit] = min(dp[j | bit], dp[j] + a)
if dp[-1] == INF:
    print(-1)
else:
    print(dp[-1])