H,N=map(int,input().split())
magic=[]
for _ in range(N):
    A,B=map(int,input().split())
    magic.append((A,B))

inf=float("inf")
dp=[inf]*(H+1)
dp[0]=0

for i in range(H):
    for a,b in magic:
        d=min(i+a,H)
        dp[d]=min(dp[d],dp[i]+b)
print(dp[H])