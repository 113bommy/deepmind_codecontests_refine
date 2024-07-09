N = int(input())
a_list = list(map(int, input().split()))

dp = [[[0]*(N+2) for _ in range(N+2)] for _ in range(N+2)]

cnt = {1:0, 2:0, 3:0}
for a in a_list:
    cnt[a] += 1

for i in range(N+1):
    for j in range(N+1):
        for k in range(N+1):
            if i==0 and j==0 and k==0:
                continue
            dp[i][j][k] += (N/(i+j+k))
            if k >= 1:
                dp[i][j][k] += dp[i][j][k-1] * (k/(i+j+k))
            if j >= 1:
                dp[i][j][k] += dp[i][j-1][k+1] * (j/(i+j+k))
            if i >= 1:
                dp[i][j][k] += dp[i-1][j+1][k] * (i/(i+j+k))
print(dp[cnt[3]][cnt[2]][cnt[1]])