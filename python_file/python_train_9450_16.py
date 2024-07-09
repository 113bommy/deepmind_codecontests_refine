n,k=map(int,input().split())
a=list(map(int,input().split()))

d=60
dp=[[-1]*n for i in range(d+1)]
for i,aa in enumerate(a):
  dp[0][i]=aa-1
for i in range(d):
  for j in range(n):
    dp[i+1][j]=dp[i][dp[i][j]]
ans=0
for i in range(d):
  if k&(1<<i):
    ans=dp[i][ans]
print(ans+1)
