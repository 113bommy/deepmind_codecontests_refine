from itertools import accumulate

N, *A = map(int, open(0).read().split())

S = [0] + list(accumulate(A))

memo = [[-1] * N for _ in range(N)]
def dp(L, R):
    if L == R:
        return 0
    if memo[L][R] >= 0:
        return memo[L][R]

    memo[L][R] = min(dp(L, c) + dp(c + 1, R) + S[R + 1] - S[L] for c in range(L, R))
    return memo[L][R]

print(dp(0, N - 1))