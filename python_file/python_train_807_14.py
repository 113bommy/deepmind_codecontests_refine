N = int(input())
A = [int(v) for v in input().split()]
P = sorted([(v, i) for i, v in enumerate(A)], key=lambda x: x[0], reverse=True)
dp = [[0 for j in range(2005)] for i in range(2005)]

for i in range(N):
    pi = P[i][1]
    for l in range(i+1):
        r = i - l
        dp[i+1][l+1] = max(dp[i+1][l+1], dp[i][l] + (pi - l) * A[pi])
        dp[i+1][l] = max(dp[i+1][l], dp[i][l] + ((N-r-1) - pi) * A[pi])

ans = 0
for i in range(N+1):
    ans = max(ans, dp[N][i])

print(ans)
