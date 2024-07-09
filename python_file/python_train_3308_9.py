import sys


def get_solve():
    cache = [None] * precalc_limit
    cache[0] = [0] * (weight_limit + 1)
    _vvv = vvv
    _www = www
    _weight_limit = weight_limit

    def _f(u):
        """ u < precalc_limit """
        if cache[u] is not None:
            return cache[u]
        dp = _f(u >> 1).copy()
        v = _vvv[u]
        w = _www[u]
        for x in range(_weight_limit, w - 1, -1):
            nv = dp[x - w] + v
            if dp[x] < nv:
                dp[x] = nv
        cache[u] = dp
        return dp

    return _f


n, *inp = map(int, sys.stdin.buffer.read().split())
vvv = [0] + inp[0:n * 2:2]
www = [0] + inp[1:n * 2:2]

weight_limit = 10 ** 5
precalc_limit = min(1 << 10, n + 1)

solve = get_solve()

buf = []
mp = iter(inp[n * 2 + 1:])
for u, l in zip(mp, mp):
    if u < precalc_limit:
        dp = solve(u)
        buf.append(dp[l])
        continue
    dp_w = [0]
    dp_v = [0]
    while u >= precalc_limit:
        v = vvv[u]
        w = www[u]
        for i in range(len(dp_w)):
            nw = dp_w[i] + w
            if nw > l:
                continue
            nv = dp_v[i] + v
            dp_w.append(nw)
            dp_v.append(nv)
        u >>= 1
    ans = 0
    dp = solve(u)
    for w, v in zip(dp_w, dp_v):
        nv = v + dp[l - w]
        if ans < nv:
            ans = nv
    buf.append(ans)

print('\n'.join(map(str, buf)))
