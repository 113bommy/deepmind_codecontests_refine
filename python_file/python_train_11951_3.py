N,K = map(int,input().split())
H = [0] + list(map(int,input().split()))

INF = float('inf')
dp = [[INF]*(N-K+1) for _ in range(N+1)]
dp[0][0] = 0

for i,h in enumerate(H):
    if i==0: continue
    for j in range(N-K,0,-1):
        for k in range(i):
            c = max(0, h - H[k])
            dp[i][j] = min(dp[i][j], dp[k][j-1] + c)
print(min(row[-1] for row in dp))