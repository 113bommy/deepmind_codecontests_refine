a, b = map(int, input().split())
if b < 2:
    print(a * a - b)
    print('o' * a + 'x' * b)
elif a == 0:
    print(- b * b)
    print('x' * b)
else:
    s = a * a - b * b
    for i in range(2, min(a + 1, b) + 1):
        u, v = b // i, b % i
        d = i - 2 + (a - i + 2) ** 2 - (u ** 2) * (i - v) - ((u + 1) ** 2) * v
        if d > s: s, q, p, j = d, u, v, i
    k = 2 * j - 1
    t = [0] * k
    t[1: k: 2] = ['o'] * (j - 2) + ['o' * (a - j + 2)]
    t[0: k: 2] = ['x' * q] * (j - p) + ['x' * (q + 1)] * p
    print(s)
    print(''.join(t))