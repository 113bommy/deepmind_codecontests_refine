# E - Active Infants

n = int(input())
a = list(map(int, input().split()))
assert len(a) == n

# 添字のリスト
p = list(range(n))
p.sort(key=lambda i: a[i])

# dp[(j, i)] = 位置jから幅iの区間に小さい方からi個を配置したときの最大うれしさ
dp = {(j, 0): 0 for j in range(n + 1)}

for i in range(n):
    for j in range(n - i):
        dp[(j, i + 1)] = \
            max(dp[(j,     i)] + a[p[i]] * abs(p[i] - (j + i)),
                dp[(j + 1, i)] + a[p[i]] * abs(p[i] - j))

print(dp[(0, n)])
