import sys
sys.setrecursionlimit(1000000)


def input():
    return sys.stdin.readline()


n, u, v = [int(i) for i in input().split()]
u -= 1
v -= 1
e = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = [int(i)-1 for i in input().split()]
    e[a].append(b)
    e[b].append(a)

uu = [0] * n
vv = [0] * n


def dfs(ve, r=u, d=0, rr=-1):
    ve[r] = d
    for i in e[r]:
        if i == rr:
            continue
        dfs(ve, i, d + 1, r)


dfs(uu, u)
dfs(vv, v)


ans = 0
for i, j in zip(uu, vv):
    if i <= j:
        ans = max(ans, j)
print(ans-1)
