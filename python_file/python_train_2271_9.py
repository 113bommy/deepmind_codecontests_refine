I = [int(_) for _ in open(0).read().split()]
N = I[0]
W, S, V = I[1::3], I[2::3], I[3::3]
dp = [-float('inf')] * (2 * 10**4 + 5)
dp[0] = 0
#dp[重さの総和]=その重さの総和になる最大価値
for s, w, v in sorted(zip(S, W, V), key=lambda swv: swv[0] + swv[1]):
    for wbefore in range(s, -1, -1):
        dp[wbefore + w] = max(dp[wbefore + w], dp[wbefore] + v)
print(max(dp))
