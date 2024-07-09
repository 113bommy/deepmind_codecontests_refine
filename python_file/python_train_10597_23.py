N, M = map(int, input().split())

dp = [float('inf')] * (2 ** N)


dp[0] = 0

for _ in range(M):
    a, b = map(int, input().split())
    c = sum(1 << (i - 1) for i in map(int, input().split()))
    for x in range(2 ** N):
        dp[c | x] = min(dp[c | x], dp[x] + a)

if dp[-1]==float('inf'):
    print(-1)
else:
    print(dp[-1])