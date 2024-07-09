N, T = map(int, input().split())
AB = [tuple(map(int, input().split())) for _ in range(N)]
AB.sort()
INF = float('inf')

dp = [-INF] * (T + 1)
dp[0] = 0

for a, b in AB:
    for t in range(T)[:: -1]:
        dp[min(T, t + a)] = max(dp[min(T, t + a)], dp[t] + b)

print(max(dp))