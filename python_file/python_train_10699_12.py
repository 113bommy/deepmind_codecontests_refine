from itertools import groupby, chain
from operator import itemgetter


def sweep(l):
    result = []
    s = set(l)
    while s:
        a = max(s)
        b = 1 << (a.bit_length() - 1)
        s = {t ^ a if t >= b else t for t in s}
        s.discard(0)
        result.append([a, b])

    return result


t = int(input())
buf = []
for _ in range(t):
    n = int(input())
    aaa = list(map(int, input().split()))
    s = input()

    if s[-1] == '1':
        buf.append(1)
        continue

    grp = [list(map(itemgetter(1), itr)) for c, itr in groupby(zip(s, aaa), key=itemgetter(0))]
    if s[0] == '0':
        grp = grp[1:]
    grp1 = grp[0::2]
    grp0 = grp[1::2]
    erasable = [False] * sum(len(g) for g in grp1)
    for i in range(len(grp1)):
        l1 = list(chain(*grp1[:i + 1]))
        l0 = list(chain(*grp0[i:]))
        s0 = sweep(l0)

        for a, b in s0:
            for i in range(len(l1)):
                if l1[i] & b:
                    l1[i] ^= a

        for j, c in enumerate(l1):
            if c == 0:
                erasable[j] = True

    if all(erasable):
        buf.append(0)
    else:
        buf.append(1)


print('\n'.join(map(str, buf)))
