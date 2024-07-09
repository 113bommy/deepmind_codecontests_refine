import sys
input = sys.stdin.buffer.readline

r, c, k = map(int, input().split())
v = [[0]*(c+1) for i in range(r+1)]
for i in range(k):
    cr, cc, cv = map(int, input().split())
    v[cr][cc] = cv

dp = [[0]*4 for _ in range(c+1)]
last = [[0]*4 for _ in range(c+1)]
for cr in range(1, r+1):
    for cc in range(1, c+1):
        upper = max(last[cc][0], last[cc][1], last[cc][2], last[cc][3])
        dp[cc][0] = max(upper, dp[cc-1][0], dp[cc][0])
        dp[cc][1] = max(dp[cc-1][1], dp[cc-1][0]+v[cr][cc], upper+v[cr][cc])
        dp[cc][2] = max(dp[cc-1][2], dp[cc-1][1]+v[cr][cc])
        dp[cc][3] = max(dp[cc-1][3], dp[cc-1][2]+v[cr][cc])
        last = dp
print(max(dp[c]))