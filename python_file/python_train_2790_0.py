import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

"""
・部分木の中で操作を行った場合の、残りdepth和の最小値と最大値を持ってdp
・補助的にコマの個数も持つ
・最大値：ただのdepthの和
・最小値：一番負担の大きな木から他の部分木を引いていった場合だが…
・最小値＋最大値から全部の最大値の和を引く形で更新
"""

N = int(readline())
S = readline().rstrip()
m = map(int,read().split())
AB = zip(m,m)

INF = 10**18

graph = [[] for _ in range(N+1)]
for a,b in AB:
    graph[a].append(b)
    graph[b].append(a)

def solve_rooted(root):
    parent = [0] * (N+1)
    ts = []
    stack = [root]
    while stack:
        x = stack.pop()
        ts.append(x)
        for y in graph[x]:
            if y == parent[x]:
                continue
            parent[y] = x
            stack.append(y)
    max_dep = [0]*(N+1)
    min_dep = [0]*(N+1)
    cnt = [0] * (N+1)
    for i,x in enumerate(S,1):
        cnt[i]=x-ord('0')
    for v in ts[::-1]:
        p = parent[v]
        max_dep_sum = 0
        x = 0
        for c in graph[v]:
            if c==p:
                continue
            cnt[v] += cnt[c]
            d1 = max_dep[c]; d2 = min_dep[c]
            d1 += cnt[c]; d2 += cnt[c]
            max_dep_sum += d1
            if x<d1+d2:
                x=d1+d2
        max_dep[v] = max_dep_sum
        x -= max_dep_sum
        if x<0:
            x=max_dep_sum&1
        min_dep[v] = x
    if min_dep[root]:
        return INF
    return max_dep[root]//2

answer = min(solve_rooted(v) for v in range(1,N+1))
if answer == INF:
    answer = -1
print(answer)