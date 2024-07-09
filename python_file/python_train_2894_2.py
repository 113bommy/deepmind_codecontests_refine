n, q = map(int, input().split())

ct = [0] * (n + 1)
e = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    a, b = map(int, input().split())
    e[a].append(b)

qs = [0] * (n + 1)
for _ in range(q):
    p, q = map(int, input().split())
    qs[p] += q

target = [1]
while len(target):
    t = target.pop()
    ct[t] += qs[t]
    for nt in e[t]:
        target.append(nt)
        ct[nt] += ct[t]

print(*ct[1:])