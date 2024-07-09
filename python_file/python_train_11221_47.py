H, N=map(int, input().split())
AB=[list(map(int, input().split())) for _ in range(N)]
dp=[0]+[float('inf') for _ in range(2*10**4)]
for a, b in AB:
  for i in range(a, H+a):
    dp[i]=min(dp[i-a]+b, dp[i])
    
print(min(dp[H:]))