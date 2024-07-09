n = int(input())
s = list(input())

dp = [[0]*(n+1) for i in range(n+1)]
for i in range(n-1,-1,-1):
    for j in range(n-1,-1,-1):
        if s[i] == s[j]:
            dp[i][j] = dp[i+1][j+1] +1
        
ans = 0
for i in range(n-1):
    for j in range(i+1,n):
        ans = max(ans,min(dp[i][j],j-i))

print(ans)