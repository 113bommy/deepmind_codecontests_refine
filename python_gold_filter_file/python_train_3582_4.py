n, t = 2 * int(input()), map(int, input().split())
d = [[] for i in range(100)]
for i, j in enumerate(t):
    d[j].append(i)
y, x = [], False
p, q = [], ['1'] * n
for i in d[10: 100]:
    if i:
        if len(i) == 1:
            if x: y.append(i[0])
            x = not x
        else:
            y.append(i[0])
            p += i[2: ]
k, l = len(p), len(y)
print(l * (n - k - l))
for i in y:
    q[i] = '2'
for i in (p[k // 2: ] if x else p[: k // 2]):
    q[i] = '2'
print(' '.join(q))