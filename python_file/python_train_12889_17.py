import bisect
N,W = map(int,input().split())
dp = [0]*(10**3+1)+[10**12]*(10**5)
for i in range(N):
    w,v = map(int,input().split())
    for j in range(len(dp)-1,1000,-1):
        dp[j] = min(dp[j],dp[j-v]+w)
print(bisect.bisect_right(dp,W)-1001)