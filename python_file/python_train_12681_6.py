s=str(input())
t=str(input())
n,m=len(s),len(t)
ans=''
dp=[[0]*(m+1) for _ in range(n+1)]
for i in range(n):
  for j in range(m):
    if s[i]==t[j]:
      dp[i+1][j+1]=max(dp[i][j]+1,dp[i+1][j+1])
    else:
      dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])
while m>0 and n>0:
  if s[n-1]==t[m-1]:ans=s[n-1]+ans;n-=1;m-=1
  elif dp[n][m]==dp[n-1][m]:n-=1
  else:m-=1
print(ans)