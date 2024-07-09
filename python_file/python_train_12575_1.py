N = int(input())
S = input()
#dp[i][j] S[i-x:i+1]==S[j-x:j+1]となる最大のx
dp = [[0] * (N + 1) for _ in range(N + 1)]
ans = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        if S[i] == S[j]:
            dp[i][j] = min(dp[i - 1][j - 1] + 1, j - i)
    ans = max(dp[i] + [ans])
print(ans)
