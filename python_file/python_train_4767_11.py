# 解説放送

def main():
    from itertools import islice, tee

    k, q = map(int, input().split())
    *d, = map(int, input().split())
    for g in tee(d, q):
        n, x, m = map(int, input().split())
        g = map(lambda x: x % m, g)
        g1, g2, g3 = tee(g, 3)
        rep, rest = divmod(n - 1, k)
        last = x + (sum(g1) * rep) + sum(islice(g2, 0, rest))
        eq = sum(rep + (1 if i < rest else 0) for i, gg in enumerate(g3) if gg == 0)
        ans = (n - 1) - eq - (last // m - x // m)
        print(ans)


if __name__ == '__main__':
    main()
