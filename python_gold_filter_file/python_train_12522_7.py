n, m = map(int, input().split())
A, B = input(), input()
n1, n2 = len(A), len(B)
dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]
ans = 0
for i in range(1, n1 + 1):
    for j in range(1, n2 + 1):
        if A[i - 1] != B[j - 1]:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1
        else:
            dp[i][j] = max(2, dp[i - 1][j - 1] + 2)
            ans = max(ans, dp[i][j])
print(ans)