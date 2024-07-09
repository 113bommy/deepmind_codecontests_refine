N, M = map(int, input().split())

dp = [float('inf')] * (1 << N)
dp[0] = 0

u = 1 << N
for i in range(M):
    a, b = map(int, input().split())
    c = sum(1 << (x - 1) for x in map(int, input().split()))

    for j in range(u):
        dp[c | j] = min(dp[c | j], dp[j] + a)


if dp[-1] != float('inf'):
    print(dp[-1])
else:
    print(-1)
