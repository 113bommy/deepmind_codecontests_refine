def main():
    n, a, b, t = map(int, input().split())
    a1 = a + 1
    b += a1
    l, res = [b if c == "w" else a1 for c in input()], []
    l[0] = x = l[0] - a
    if t <= x:
        print(int(t == x))
        return
    f = res.append
    for dr in (0,):
        if dr:
            l[1:] = l[-1:-n:-1]
        tot = t
        for hi, x in enumerate(l):
            tot -= x
            if tot < 0:
                break
        else:
            print(n)
            return
        f(hi)
        tot += x
        hi -= 1
        tot -= hi * a
        lo = n
        while True:
            while lo > 0 <= tot:
                lo -= 1
                tot -= l[lo]
            f(n + hi - lo)
            if not (lo and hi):
                break
            while tot <= 0 < hi:
                tot += l[hi] + a
                hi -= 1
    print(max(res))


if __name__ == '__main__':
    main()
