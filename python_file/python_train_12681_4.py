s = input()
t = input()
S = len(s)
T = len(t)
dp = [[0]*(T+1) for _ in range(S+1)]

for i in range(S):
    for j in range(T):
        if s[i] == t[j]:
            dp[i+1][j+1] = dp[i][j] + 1
        else:
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])

ans = ""
while S and T:
    if dp[S][T] == dp[S-1][T]:
        S -= 1
    elif dp[S][T] == dp[S][T-1]:
        T -= 1
    else:
        ans = s[S-1]+ans
        S -= 1
        T -= 1
print(ans)
