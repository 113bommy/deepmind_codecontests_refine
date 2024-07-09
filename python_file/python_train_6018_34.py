M=10**9+7
s=input()
r=range
dp=[[0]*13,[0]*13]
dp[0][0]=1
t=0
for c in s:
  for i in r(13):
    if c=='?':
      for j in r(10):
        dp[t^1][(i*10+j)%13]+=dp[t][i]
    else:
      dp[t^1][(i*10+int(c))%13]+=dp[t][i]
  dp[t]=[0]*13
  t^=1
  for i in r(13): dp[t][i]%=M
print(dp[len(s)%2][5])