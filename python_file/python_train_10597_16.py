n, m = map(int, input().split())

INF = float('inf')
dp = [INF for j in range(2**n)]

dp[0] = 0

for i in range(m):
    a, b = map(int, input().split())
    c = map(int, input().split())

    k = 0
    for ci in c:
        ci -= 1
        k |= (1 << ci)
    for j in range(2**n):
        l = k | j
        dp[l] = min(dp[l], dp[j] + a)

if dp[2**n-1] == INF:
    print(-1)
else:
    print(dp[2**n-1])
