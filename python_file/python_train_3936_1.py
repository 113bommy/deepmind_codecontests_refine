from functools import lru_cache


def prepare(n, MOD):
    f = 1
    factorials = [1]
    for m in range(1, n + 1):
        f *= m
        f %= MOD
        factorials.append(f)
    inv = pow(f, MOD - 2, MOD)
    invs = [1] * (n + 1)
    invs[n] = inv
    for m in range(n, 1, -1):
        inv *= m
        inv %= MOD
        invs[m - 1] = inv

    return factorials, invs


def get_nhr(n, facts, invs):
    @lru_cache(maxsize=None)
    def nhr(r):
        return facts[n + r - 1] * invs[r] * invs[n - 1] % MOD

    return nhr


MOD = 998244353
n, m = list(map(int, input().split()))
facts, invs = prepare(n + 3 * m, MOD)
nhr = get_nhr(n, facts, invs)
ans = 0
for odd in range(m % 2, min(m, n) + 1, 2):
    tmp = nhr((3 * m - odd) // 2)
    if odd > 0:
        tmp -= odd * nhr((m - odd) // 2)
    if odd < n and odd <= m - 2:
        tmp -= (n - odd) * nhr((m - odd - 2) // 2)
    ans = (ans + facts[n] * invs[odd] * invs[n - odd] % MOD * tmp) % MOD
print(ans)
