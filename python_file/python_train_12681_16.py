s=input()
t=input()
n=len(s)
m=len(t)

dp=[[0]*(m+1) for i in range(n+1)]

for i in range(n):
  for j in range(m):
    if s[i]==t[j]:
      dp[i+1][j+1]=dp[i][j]+1

    else:
      dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])

#print(dp[n][m])

ans=''
while n>=0 and m>=0:
  if dp[n][m]==dp[n-1][m]:
    n-=1

  elif dp[n][m]==dp[n][m-1]:
    m-=1

  else:
    n-=1
    m-=1
    ans+=s[n]

print(ans[::-1])