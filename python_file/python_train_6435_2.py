from collections import Counter


def slv(K, D):
    rl = Counter()
    r = Counter()
    rl[0] = 1

    M = 10**9 + 7
    for c in K:
        d = int(c)
        rln = Counter()
        rn = Counter()
        for rem, count in rl.items():
            rln[(rem + d) % D] += count
            rln[(rem + d) % D] %= M

        for rem, count in rl.items():
            for i in range(d):
                rn[(rem + i) % D] += count
                rn[(rem + i) % D] %= M
        for rem, count in r.items():
            for i in range(10):
                rn[(rem + i) % D] += count
                rn[(rem + i) % D] %= M
        rl = rln
        r = rn
    return (rl[0] + r[0] - 1) % M


K = input()
D = int(input())
print(slv(K, D))
