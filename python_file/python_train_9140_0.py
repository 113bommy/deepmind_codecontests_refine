N = int(input())
P = list(map(float, input().split()))


def solve():
    dp = [[0]*(i+3) for i in range(N+1)]
    dp[0][1] = 1
    for i in range(1,N+1):
        for j in range(1,i+2):
            dp[i][j] = dp[i-1][j-1]*P[i-1]+dp[i-1][j]*(1-P[i-1])
    ans = sum(dp[-1][(N+3)//2:])
    return ans
print(solve())