n,k=map(int, input().split())
h=list(map(int, input().split()))
dp=[0]*n
for i in range(1,n):
    dp[i]=min([dpj+abs(h[i]-hj) for dpj,hj in zip(dp[max(0,i-k):i],h[max(0,i-k):i])])
print(dp[-1])