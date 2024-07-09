import sys
input=sys.stdin.readline
n,m=map(int,input().split())
trs=[]
for _ in range(m):
  a,b=map(int,input().split())
  c=list(map(int,input().split()))
  cnt=0
  for i in range(b):
    cnt+=2**(c[i]-1)
  trs.append((a,cnt))
dp=[10**9]*2**n
dp[0]=0
for i in range(2**n):
  for a,cnt in trs:
    dp[i|cnt]=min(dp[i]+a,dp[i|cnt])
if dp[2**n-1]!=10**9:
  print(dp[2**n-1])
else:
  print(-1)