from itertools import product
n, m = map(int, input().split())
can_open = []
cost = []
for _ in range(m):
    a, b = map(int, input().split())
    cost.append(a)
    can_open.append(sum(1 << (c-1) for c in map(int, input().split())))

n_bit = 1 << n
INF = 10**18
dp = [INF]*n_bit
dp[0] = 0

for j, (x, y) in product(range(n_bit), zip(can_open, cost)):
    m = j | x
    dp[m] = min(dp[m], dp[j]+y)

print(dp[-1] if dp[-1] != INF else -1)