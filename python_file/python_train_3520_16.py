import itertools

N = int(input())
A = tuple(map(int, input().split()))
S = [0] + list(itertools.accumulate(A))

dp = [[0] * (N + 1) for _ in range(N + 1)]
for length in range(2, N + 1):
    for l in range(N - length + 1):
        r = length + l
        dp[l][r] = min(dp[l][m] + dp[m][r] for m in range(l + 1, r)) + S[r] - S[l]
print(dp[0][N])
