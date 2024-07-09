N = int(input())
S = input()

dp = [[0] * (N + 1) for _ in range(N + 1)]
ans = 0

for i in range(N - 1, -1, -1):
    for j in range(N - 1, -1, -1):
        if i >= j: break
        if S[i] == S[j]:
            dp[i][j] = min(1 + dp[i + 1][j + 1], j - i)
            if dp[i][j] > ans:
                ans = dp[i][j]
print(ans)
