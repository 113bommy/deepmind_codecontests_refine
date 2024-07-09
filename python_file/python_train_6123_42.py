import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5+100)

def dfs(v, pv, c):
    if memo[v][c]!=-1:
        return memo[v][c]
        
    res = 1
    
    for nv in G[v]:
        if nv==pv:
            continue
        
        if c==0:
            res *= dfs(nv, v, 0)+dfs(nv, v, 1)
        else:
            res *= dfs(nv, v, 0)
        
        res %= MOD
    
    memo[v][c] = res
    
    return res

N = int(input())
G = [[] for _ in range(N)]

for _ in range(N-1):
    x, y = map(int, input().split())
    G[x-1].append(y-1)
    G[y-1].append(x-1)

memo = [[-1]*2 for _ in range(N)]
MOD = 10**9+7

print((dfs(0, -1, 0)+dfs(0, -1, 1))%MOD)