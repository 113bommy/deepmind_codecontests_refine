N,K = map(int,input().split())
H = list(map(int,input().split()))

dp = [0]*N
for i in range(1,N):
    dp[i] = min(abs(H[i]-H[i-n]) + dp[i-n] for n in range(1,min(K+1,i+1)))

print(dp[-1])