mod = 10**9+7
 
s = input()
n = len(s)
 
dp = [0]*13
dp[0] = 1
 
for i in range(n):
  dp2 = [0]*13  
  for j in range(10):
    if s[i] == '?' or s[i] == str(j):
      for k in range(13):
        dp2[(k*10 + j)%13] += dp[k]
        dp2[(k*10 + j)%13] %= mod
        
  dp = dp2
 
print(dp[5])