n = int(input())
s = input() + '_'
    
dp = [[0]*(n+1) for i in range(n+1)]
for i in range(n-2, -1, -1):
    for j in range(n-1, i,-1):
        if i + dp[i+1][j+1] >= j:
            break
        if s[i] == s[j]:
            dp[i][j] = dp[i+1][j+1] + 1
print(max(list(map(lambda x: max(x), dp))))