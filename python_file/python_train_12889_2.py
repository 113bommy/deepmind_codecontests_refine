N, W = [int(_) for _ in input().split()]
WV = [[int(_) for _ in input().split()] for _ in range(N)]
dp = {}
dp[0] = 0
for w, v in WV:
    dp_o = dp.copy()
    for k in dp_o:
        dp[k + v] = min(dp_o.get(k + v, float('inf')), dp_o[k] + w)
print(max([k for k, v in dp.items() if v <= W]))
