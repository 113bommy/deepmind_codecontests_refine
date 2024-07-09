N,T = map(int,input().split())
item=sorted([list(map(int,input().split())) for _ in range(N)],key=lambda x:x[0])

dp=[0]*(T+1)

for a,b in item:
    for t in reversed(range(T)):
        dist=min(T,t+a)
        dp[dist] = max(dp[t]+b,dp[dist])
print(max(dp))
