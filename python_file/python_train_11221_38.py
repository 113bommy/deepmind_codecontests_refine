H,N=map(int,input().split())
A=[0]*N
B=[0]*N
for i in range(N):
  A[i],B[i]=map(int,input().split())
dp = [99999999999]*(H+1)
dp[0]=0
for h in range(H):
  for i in range(N):
    dp[min(H,h+A[i])]=min(dp[h] + B[i], dp[min(H,h+A[i])])
print(dp[-1])