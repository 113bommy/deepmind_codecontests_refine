def rec(frm, to):
    """return: [frm,to)の合体コスト最小値"""
    if to - frm == 1:
        return 0

    if memo[frm][to]:
        return memo[frm][to]

    res = inf
    for mid in range(frm + 1, to):
        res = min(res, rec(frm, mid) + rec(mid, to))
    res += cum_sum[to] - cum_sum[frm]

    memo[frm][to] = res
    return res


inf = float('inf')

n = int(input())
a = list(map(int, input().split()))

cum_sum = [0] * (n + 1)
for i, aa in enumerate(a):
    cum_sum[i + 1] = cum_sum[i] + aa

memo = [[None] * (n + 1) for _ in range(n + 1)]
# memo[frm][to] = メモ化

print(rec(0, n))
