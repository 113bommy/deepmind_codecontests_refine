import os
import sys
from collections import defaultdict

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7


# MOD = 998244353

def div_mod(a, b, mod):
    return a * pow(b, mod - 2, mod) % mod


N = int(sys.stdin.buffer.readline())
AB = [list(map(int, sys.stdin.buffer.readline().split())) for _ in range(N - 1)]

graph = [[] for _ in range(N)]
for a, b in AB:
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)

# 頂点ごとに穴あきになる確率を調べる
# 全パターン数 2^N を掛けて合計すればいい
# 自分をrootにしたときに黒をもつ子が2つ以上ある

children_counts = [defaultdict(int) for _ in range(N)]
hist = []
root = 0
stack = [(root, None)]
while stack:
    v, parent = stack.pop()
    hist.append((v, parent))
    for u in graph[v]:
        if u == parent:
            continue
        stack.append((u, v))
hist.reverse()
dfs = [0] * N
for v, parent in hist:
    ret = 0
    for u in graph[v]:
        if u == parent:
            continue
        cnt = dfs[u]
        children_counts[v][cnt] += 1
        ret += cnt
    ret += 1
    if v != root:
        children_counts[v][N - ret] += 1
    dfs[v] = ret
# print(dfs)

pow2 = [1]
p = 1
for _ in range(N):
    p = (p * 2) % MOD
    pow2.append(p)

# 穴あきにならない期待値
E = [0] * N
for v, counts in enumerate(children_counts):
    if len(graph[v]) == 1:
        # 端っこ
        E[v] = pow2[N]
        continue
    # 黒のときはどう選んでもダメ
    e = pow2[N - 1]
    # 1つだけ黒が含まれる確率は
    for children, cnt in counts.items():
        # ほかが全部白なのは1パターン
        # 1つ以上黒が含まれるのは
        curo = pow2[children] - 1
        e += (curo * cnt) % MOD
    # 自分の色は白
    # 全部白のパターン加算
    E[v] = (e + 1) % MOD
# 穴あきになる期待値
E = [(pow2[N] - e) % MOD for e in E]
ans = div_mod(sum(E), pow2[N], MOD)
print(ans)
