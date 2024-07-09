N,K=map(int,input().split())
H=list(map(int,input().split()))
dp=[0]*N

for i in range(N-1):
  A=[]
  for j in range(K):
    if i-j>=0:
      A.append(dp[i-j]+abs(H[i-j]-H[i+1]))
  dp[i+1]=min(A)

print(dp[N-1])