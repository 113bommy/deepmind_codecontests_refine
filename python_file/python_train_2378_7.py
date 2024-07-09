"""
奇数本で構成される閉路が存在している場合、全ての頂点同士を結ぶことができる
そうでない場合、、、
奇数本でつながっている辺同士は直接結ぶことができる＝グラフっは二部グラフとなっていて、
AグループとBグループのノード同士を結ぶことができる。
"""

import sys
sys.setrecursionlimit(200000)

N,M = map(int,input().split())
edges = [[] for _ in range(N+1)]

for _ in range(M):
    a,b = map(int,input().split())
    edges[a].append(b)
    edges[b].append(a)

steps = [None]*(N+1)

def dfs(node,step):
    if steps[node] != None:
        if (step - steps[node])%2 == 1:
            return True
        else:
            return False
    else:
        steps[node] = step
        res = False
        for nx in edges[node]:
            res = res or dfs(nx,step+1)
        return res

res = dfs(1,0)
def choose(n,k):
    import math
    return math.factorial(n)//(math.factorial(n-k)*math.factorial(k))
if res:
    print(choose(N,2)-M)
else:
    for i in range(1,N+1):
        steps[i] %= 2
    odd = steps.count(1)
    even = N - odd
    print(odd*even-M)

