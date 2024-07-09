n,k=map(int,input().split())
hl=list(map(int,input().split()))
dp=[0]
for i in range(1,n):
    t=[]
    for j in range(1,min(i+1,k+1)):
        t.append(dp[i-j]+abs(hl[i-j]-hl[i]))
    dp.append(min(t))
print(dp[-1])