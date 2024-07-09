mod = 10**9 + 7

def accmulate(array):
    cs = [0]*(len(array)+1)
    for i in range(len(array)):
        cs[i+1] = cs[i] + array[i]
    return cs

def query(l,r):
    return cs[r+1] - cs[l]

N,K = map(int,input().split())
A = list(map(int,input().split()))

dp = [[0]*(K+1) for _ in range(N+1)]

dp[0][0] = 1

for i in range(1,N+1):
    cs = accmulate(dp[i-1])
    for j in range(K+1):
        dp[i][j] += query(max(j-A[i-1], 0), j)
        dp[i][j] %= mod

ans = dp[N][K]
print(ans)