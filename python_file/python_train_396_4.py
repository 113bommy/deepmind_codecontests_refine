from collections import defaultdict
s = input()
n = len(s)
dp = defaultdict(int)
dp[0] = 1
ls = [1<<(ord(s[0])-97)]
for i in range(1,n):
  ls.append(ls[-1]^(1<<(ord(s[i])-97)))
if ls[-1] == 0:
  print(1)
  exit()
for i in range(n):
  for b in range(26):
    bit = 1<<b
    if dp[ls[i]^bit] == 0:
      continue
    if dp[ls[i]] == 0:
      dp[ls[i]] = dp[ls[i]^bit]+1
    else:
      dp[ls[i]] = min(dp[ls[i]^bit]+1,dp[ls[i]])
print(dp[ls[n-1]]-1)