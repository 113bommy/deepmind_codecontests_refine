n,k=map(int,input().split())
h=[int(i) for i in input().split()]
dp=[0]*n
dp[1]=abs(h[1]-h[0])
for i in range(2,n):
    dp[i]=min([abs(h[j]-h[i])+dp[j] for j in range(max(0,i-k),i)])
print(dp[-1])