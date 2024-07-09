INF = 10000
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

def popcount(x):
    x = x - ((x >> 1) & 0x5555555555555555)
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f
    x = x + (x >> 8)
    x = x + (x >> 16)
    x = x + (x >> 32)
    return x & 0x0000007f

dp = [[INF for i in range(N)] for j in range(1 << N)]

for i in range(N):
    dp[1 << i][i] = i

for i in range(1 << N):
    for j in range(N):
        if i >> j & 1:
            if (popcount(i) - j) % 2 != 0:
                num = A[j]
            else:
                num = B[j]
            cnt = 0
            for k in range(N):
                if not (i >> k & 1):
                    if (popcount(i) - k) % 2 == 0:
                        num2 = A[k]
                    else:
                        num2 = B[k]
                    if num <= num2:
                        dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + cnt)
                    cnt += 1

ans = INF
for i in range(N):
    ans = min(ans, dp[(1 << N) - 1][i])

if ans == INF:
    print(-1)
else:
    print(ans)