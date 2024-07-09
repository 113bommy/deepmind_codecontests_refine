N,W=map(int,input().split())
wv = [tuple(map(int,input().split())) for _ in range(N)]

V = sum([wv[i][1] for i in range(N)])

dp = [W+1] * (V + 1)
dp[0] = 0
for i in range(N):
  w,v=wv[i]
  for j in range(V, v-1, -1):
    dp[j] = min(dp[j-v] + w, dp[j])
    
print(max(i for i in range(V+1) if dp[i] <= W))