import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5+100)

def dfs(v):
    l = []
    
    for nv in G[v]:
        l.append(dfs(nv))
    
    l.sort(reverse=True)
    res = 0
    
    for i in range(len(l)):
        res = max(res, l[i]+i+1)
    
    return res

N = int(input())
G = [[] for _ in range(N)]

for i in range(1, N):
    a = int(input())
    G[a-1].append(i)

print(dfs(0))