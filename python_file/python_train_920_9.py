import sys
input = sys.stdin.readline

N, X = map(int, input().split())
A = list(map(int, input().split()))

dp = [[None for _ in range(N)] for _ in range(N)]
for i in range(N):
    dp[0][i] = A[i]

ans = sum(dp[0])
for d in range(1, N):
    for i in range(N):
        dp[d][i] = min(dp[d-1][i], A[(i+d)%N])
    ans = min(ans, sum(dp[d])+X*d)

print(ans)