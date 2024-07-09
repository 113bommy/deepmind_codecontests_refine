H, N, *AB = map(int, open(0).read().split())
A = AB[::2]
B = AB[1::2]

dp = [float("inf")] * (H + 1)
dp[0] = 0

for i in range(N):
    for h in range(H):
        dec_health = min(h + A[i], H)
        dp[dec_health] = min(dp[dec_health], dp[h] + B[i])
print(dp[-1])
