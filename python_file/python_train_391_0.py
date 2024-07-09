import sys

sys.setrecursionlimit(10 ** 7)

n, u, v = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)


ftakahasi = [-1 for i in range(n)]
faoki = [-1 for i in range(n)]


def dfst(i, n):
    ftakahasi[i] = n
    for sg in g[i]:
        if ftakahasi[sg] == -1:
            dfst(sg, n + 1)


def dfsa(i, n):
    faoki[i] = n
    for sg in g[i]:
        if faoki[sg] == -1:
            dfsa(sg, n + 1)


dfst(u - 1, 0)
dfsa(v - 1, 0)
res1 = 0
for i in range(n):
    pt = ftakahasi[i]
    pa = faoki[i]
    if pt < pa:
        tres = pa - 1
        res1 = max(res1, tres)
print(res1)
