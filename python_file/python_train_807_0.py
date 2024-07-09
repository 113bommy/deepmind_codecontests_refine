n=int(input())
a=map(int,input().split())

b = [ (a,i) for i,a in enumerate(a)]

b.sort(reverse=True)

dp=[ [0] * (n+1) for i in range(n+1) ]

ans=0

for l in range(n):
  for r in range(n):
    if l + r == n:
      ans = max( ans, dp[l][r] )
      break
    act , i = b[l+r]
    dp[l+1][r] = max( dp[l+1][r] , dp[l][r] +act*abs(i-l))
    dp[l][r+1] = max( dp[l][r+1] , dp[l][r] +act*abs(n-i-1-r))
print(ans)