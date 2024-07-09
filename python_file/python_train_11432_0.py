#n = int(input())
#s = input()
n,x = map(int,input().split())
da = list(map(int,input().split()))
m = 100010
mod = 1000000007

dp = [0 for i in range(m)]
da.sort()
da.reverse()
dp[x] = 1
for i in range(n):
    for j in range(m):
        if j >= da[i]:
            dp[j%da[i]] += dp[j]
            dp[j] *= n-i-1
            if dp[j] >= mod: dp[j] %= mod
            if dp[j%da[i]] >= mod: dp[j] %= mod
        else:
            dp[j] *= n-i
            if dp[j] >= mod: dp[j]%=mod
ans = 0
for i in range(m):
    ans += dp[i] * i
    if ans >= mod: ans %= mod
print(ans)
