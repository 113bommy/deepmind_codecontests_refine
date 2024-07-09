N, K = map(int, input().split())
a = list(map(int, input().split()))
dp = [False] * (K + 1)
for i in range(1, K + 1):
    for j in range(N):
        if i - a[j] >= 0:
            dp[i] |= not dp[i - a[j]]

if dp[K]:
    print('First')
else:
    print('Second')