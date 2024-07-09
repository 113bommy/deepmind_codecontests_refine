n,k=map(int,input().split())
h=list(map(int,input().split()))
dp=[0]*n
for i in range(1,n):
    cnt=[]
    for j in range(max(0,i-k),i):
        cnt.append(dp[j]+abs(h[j]-h[i]))
    dp[i]=min(cnt)
print(dp[-1])
