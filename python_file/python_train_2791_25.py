n,k,*h=map(int,open(0).read().split());
dp=[0]*n;
for i in range(1,n):
    dp[i]=min(dp[j+max(i-k,0)]+abs(a-h[i])for j,a in enumerate(h[max(i-k,0):i]));
print(dp[-1])