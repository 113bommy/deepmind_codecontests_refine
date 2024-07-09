import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
edge = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    x, y = map(int, input().split())
    edge[x].append(y)
    edge[y].append(x)
M = int(input())
AB = tuple(tuple(map(int, input().split())) for _ in range(M))


parent = [-1] * (N + 1)
node = [1]
while node:
    s = node.pop()
    for t in edge[s]:
        if t == parent[s]:
            continue
        parent[t] = s
        node.append(t)

pair = [-1] * M
for i, (a, b) in enumerate(AB):
    pa = set()
    pb = set()
    while a != 1:
        pa.add(a - 1)
        a = parent[a]
    while b != 1:
        pb.add(b - 1)
        b = parent[b]
    pair[i] = pa ^ pb

ans = pow(2, N - 1)

whole = set(range(1, N))
for bit in range(1, 1 << M):
    popcnt = 0
    inter = set()
    for i in range(M):
        if (bit >> i) & 1:
            popcnt += 1
            inter |= pair[i]
    x = N - len(inter) - 1
    if popcnt % 2 == 1:
        ans -= 2 ** x
    else:
        ans += 2 ** x

print(ans)