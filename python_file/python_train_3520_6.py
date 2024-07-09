n = int(input())
s = list(map(int,input().split()))
dp = [[0 for _ in range(n)] for _ in range(n)]
psum = [0 for _ in range(n+1)]
sm = 0
for i in range(n):
    sm +=s[i]
    psum[i+1]=sm
def findMin(left,right):
    dp[left][right]=dp[left][left]+dp[left+1][right]+psum[right+1]-psum[left]
    for i in range(left+1,right):
        dp[left][right] = min(dp[left][right],dp[left][i]+dp[i+1][right]+psum[right+1]-psum[left])
for length in range(2,n+1):
    for l in range(n-length+1):
        r = l+length-1
        findMin(l,r)

print(dp[0][n-1])