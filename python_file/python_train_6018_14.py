s=input()
l=len(s)

mod=10**9+7

dp=[[0 for j in range(13)] for i in range(l)]

if s[0] =="?":
    dp[0] = [1]*10+[0]*3
else:
    dp[0][int(s[0])] =1

for i in range(1, l):
 if s[i]=='?':
   for j in range(10):
     for k in range(13):
       dp[i][(k*10+j)%13]+=dp[i-1][k]%mod
 else:
   for k in range(13):
     dp[i][(k*10+int(s[i]))%13]+=dp[i-1][k]%mod
print(dp[-1][5]%mod)
