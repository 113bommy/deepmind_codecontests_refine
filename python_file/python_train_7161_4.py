n,t=map(int,input().split())
dish=[list(map(int,input().split())) for i in range(n)]
dish.sort()
dp=[0]*6001
for i in range(n):
    a,b=dish[i]
    for j in range(t-1,-1,-1):
        dp[j+a]=max(dp[j+a],dp[j]+b)
print(max(dp))