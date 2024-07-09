# https://atcoder.jp/contests/hitachi2020/submissions/10704509

def main():
    import sys
    input = sys.stdin.readline

    inf = 1 << 30
    L = 30

    N, T = map(int, input().split())

    ps = []
    coef_0 = []
    for _ in range(N):
        a, b = map(int, input().split())
        if a == 0:
            coef_0.append(b + 1)
        else:
            ps.append((a, b))  # namedtupleやめた,coef,const

    ps.sort(key=lambda p: p[0] / (p[1] + 1), reverse=True)
    coef_0.sort()

    dp = [inf] * (L + 1)
    dp[0] = 0
    for coef, const in ps:
        for visited in reversed(range(L)):
            dp[visited + 1] = min(
                dp[visited + 1],
                (dp[visited] + 1) * (coef + 1) + const
            )

    def accumulate(a):
        s = 0
        yield s  # start=x->0
        for x in a:
            s += x
            yield s

    *acc, = accumulate(coef_0)

    ans = {0}
    cnt = len(acc) - 1
    for visited, consumption_time in enumerate(dp):
        rest = T - consumption_time
        if rest < 0: break  # le->lt,continue->break,restは狭義単調減少
        while cnt > 0 and acc[cnt] > rest:  # bisect_right->しゃくとり
            cnt -= 1
        ans.add(visited + cnt)
    print(max(ans))


if __name__ == '__main__':
    main()
