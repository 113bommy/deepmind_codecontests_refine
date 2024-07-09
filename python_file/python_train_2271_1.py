N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]
src.sort(key=lambda x:x[0]+x[1])

dp = [None] * (20001)
dp[0] = 0
for w,s,v in src:
    for s0 in range(s,-1,-1):
        if dp[s0] is None: continue
        if dp[s0+w] is None:
            dp[s0+w] = dp[s0] + v
        else:
            dp[s0+w] = max(dp[s0+w], dp[s0] + v)
print(max(v for v in dp if v is not None))