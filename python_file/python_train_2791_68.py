N,K = map(int,input().split())
h = list(map(int,input().split()))
DP = [float('inf')]*N
DP[0] = 0
for i in range(0,N):
    for j in range(i+1,min(N,i+K+1)):
        DP[j] = min(DP[j],DP[i]+abs(h[i]-h[j]))
print(DP[-1])