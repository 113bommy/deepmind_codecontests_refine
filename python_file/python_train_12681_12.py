s,t = input(),input()
n,m=len(s),len(t)
dp = [[0]*(n+1) for _ in range(m+1)]

for i in range(m):
    for j in range(n):
        if s[j] == t[i]:
            dp[i+1][j+1] = max(dp[i][j]+1,dp[i+1][j+1])
        
        dp[i+1][j+1] = max(dp[i+1][j+1],dp[i+1][j], dp[i][j+1])

ans = ""
count = 0
while count != dp[-1][-1]:
    if dp[m][n] == dp[m-1][n]:
        m -= 1
    elif dp[m][n] == dp[m][n-1]:
        n -= 1
    else:
        ans += t[m-1]
        count += 1
        m -= 1
        n -= 1

print(ans[::-1])