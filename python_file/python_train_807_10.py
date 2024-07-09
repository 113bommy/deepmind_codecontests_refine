n = int(input())
a = list(map(int,input().split()))
b = list((x,i) for i,x in enumerate(a))
b.sort(reverse=True)
dp = [[0]*(n+1-i) for i in range(n+1)]
for i in range(n):
    x,idx = b[i]
    for j in range(i+1):
        k = i-j
        if dp[j+1][k] < dp[j][k] + x*(idx-j):
            dp[j+1][k] = dp[j][k] + x*(idx-j)
        if dp[j][k+1] < dp[j][k] + x*((n-1-k)-idx):
            dp[j][k+1] = dp[j][k] + x*((n-1-k)-idx)
ans = 0
for i in range(n+1):
    if ans < dp[i][n-i]:
        ans = dp[i][n-i]
print(ans)
