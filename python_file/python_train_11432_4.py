N, X = map(int, input().split())
s_list = list(map(int, input().split()))

s_list.sort(reverse=True)

mod = 10 ** 9 + 7

dp = [[0] * (X + 1) for _ in range(N + 1)]
dp[0][X] = 1

for i in range(N):
    for x in range(X + 1):
        if dp[i][x] == 0:
            continue
        s = s_list[i]
        dp[i + 1][x % s] += dp[i][x]
        dp[i + 1][x % s] %= mod
        dp[i + 1][x] += dp[i][x] * (N - i - 1)
        dp[i + 1][x] %= mod

ans = 0
for x in range(1, X + 1):
    ans += dp[N][x] * x
    ans %= mod
print(ans)
