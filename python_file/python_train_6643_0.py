import sys


def prepare(n):
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i % MOD
    inv = [1] * (n + 1)
    inv[n] = pow(fact[n], MOD - 2, MOD)
    for i in range(n - 1, 0, -1):
        inv[i] = inv[i + 1] * (i + 1) % MOD
    return fact, inv


MOD = 10 ** 9 + 7
h, w, n = map(int, input().split())
walls = [tuple(map(int, line.split())) for line in sys.stdin.readlines()]
walls.append((1, 1))
walls.append((h, w))
walls.sort()
fact, inv = prepare(h + w)
dp = [1]
for i, (cy, cx) in enumerate(walls[1:], start=1):
    res = 0
    for j, (py, px) in enumerate(walls[:i]):
        if cx < px:
            continue
        dy, dx = cy - py, cx - px
        res -= dp[j] * fact[dy + dx] % MOD * inv[dy] % MOD * inv[dx] % MOD
        res %= MOD
    dp.append(res)
print(-dp[-1] % MOD)
