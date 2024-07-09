def solve(n,a,b):
    dp=[0]*(n+1)
    for w in range(n+1): dp[w]=max(w,dp[w-a[0]]+b[0]if w-a[0]>=0 else w,dp[w-a[1]]+b[1]if w-a[1]>=0 else w,dp[w-a[2]]+b[2]if w-a[2]>=0 else w)
    return dp[-1]
N,A,B=int(input()),list(map(int, input().split())),list(map(int, input().split()))
print(solve(solve(N,A,B),B,A))