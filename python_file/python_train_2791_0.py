N,K=map(int,input().split())
h=list(map(int,input().split()))
dp=[10**10]*(N)#dp[i]→i+1番目の柱にくる最小コスト
dp[0]=0
for i in range(N-1):
    dp[i+1]=min(dp[i+1-j]+abs(h[i+1]-h[i+1-j]) for j in range(1,min(i+1,K)+1))
print(dp[N-1])