N, W = map(int, input().split())

w = [0] * N
v = [0] * N
for i in range(N):
    w[i], v[i] = map(int, input().split())

dp = {0: 0}
for i in range(N):
    for cv, cw in list(dp.items()):
        if cw + w[i] > W:
            continue
        dp[cv + v[i]] = min(
            dp.get(cv + v[i], float('inf')),
            cw + w[i])
print(max(dp))