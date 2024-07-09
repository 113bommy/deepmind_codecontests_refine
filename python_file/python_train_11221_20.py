INT_MAX = 10**8
h, n = map(int, input().split())
e = tuple(tuple(map(int, input().split())) for _ in range(n))

dp = [0] + [INT_MAX]* h
for i in range(1, h+1):
  v = INT_MAX
  for a, b in e:
    c = dp[max(0, i - a)] + b
    v = min(v, c)
  dp[i] = v
print(dp[h])