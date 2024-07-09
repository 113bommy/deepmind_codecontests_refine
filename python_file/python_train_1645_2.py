import itertools
import os
import sys
from functools import lru_cache

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 998244353

N = int(sys.stdin.readline())


@lru_cache(maxsize=None)
# @debug
def is_ok(s):
    if len(s) == 0:
        return True
    if len(s) == 2:
        return s not in ['AB', 'BA']
    for i in range(len(s) - 2):
        if s[i:i + 2] not in ['AB', 'BA'] and is_ok(s[:i] + s[i + 2:]):
            return True
    return False


def test(N):
    ret = 0
    for s in itertools.product('ABC', repeat=N):
        s = ''.join(s)
        ret += is_ok(s)
    return ret


def mod_invs(max, mod):
    """
    逆元のリスト 0 から max まで
    :param int max:
    :param int mod:
    """
    invs = [1] * (max + 1)
    for x in range(2, max + 1):
        invs[x] = (-(mod // x) * invs[mod % x]) % mod
    return invs


# print(test(N))
# N = 10 ** 7

# 解説AC
# 偶数番目のAとBを反転して、AAとBB以外を取り除く
# AまたはBが半分より多いときダメなので全体から引く
ans = pow(3, N, MOD)

invs = mod_invs(max=N, mod=MOD)
ncr = 1  # NCr
p2r = 1  # pow(2, N - r, MOD)
for r in range(N, N // 2, -1):
    # ans -= comb.ncr(N, r) * pow(2, N - r, MOD) * 2 % MOD
    ans -= ncr * p2r * 2 % MOD
    ans %= MOD
    ncr *= r * invs[N - r + 1]
    ncr %= MOD
    p2r *= 2
    p2r %= MOD
print(ans)
