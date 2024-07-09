N,K = map(int,input().split())
H = tuple(map(int,input().split()))

dp = [0]

for i in range(1,N):
  h = H[i]
  dp.append(min(dp[j]+abs(H[j]-h) for j in range(max(i-K,0),i)))

print(dp[-1])
