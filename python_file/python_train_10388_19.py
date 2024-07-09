from bisect import bisect_left as bisect
import sys
sys.setrecursionlimit(10**9)

N = int(input())
a = list(map(int,input().split()))
g = [[] for _ in range(N)]
for i in range(N-1):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)

ans = [0]*N
def dfs(t,f,l):
    res = 0
    i = bisect(l,a[t])
    if len(l)==i:
        l.append(a[t])
    else:
        res = [i,l[i]]
        l[i]=a[t]
    ans[t] = len(l)
    for v in g[t]:
        if v != f:
            back = dfs(v,t,l)
            if back:
                l[back[0]] = back[1]
            else:
                l.pop()
    return res
dfs(0,0,[])
for i in range(N):
    print(ans[i])