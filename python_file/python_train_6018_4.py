mod = 10 ** 9 + 7

S = input()

dp = [[0] * 13 for _ in range(len(S) + 1)]
dp[0][0] = 1

for i, s in enumerate(S):
    c = -1 if s == "?" else int(s)
    for j in range(10):
        if c != -1 and c != j:
            continue
        for k in range(13):
            dp[i + 1][(k * 10 + j) % 13] += dp[i][k]
    for j in range(13):
        dp[i + 1][j] %= mod

print(dp[len(S)][5])