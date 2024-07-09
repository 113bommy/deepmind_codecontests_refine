import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
G = [[] for i in range(n)]
for i in range(n-1):
    a,b = map(int, input().split())
    a,b = a-1,b-1
    G[a].append(b)
    G[b].append(a)

def dfs(cur, cost):
    dist[cur] = cost
    for to in G[cur]:
        if dist[to] == -1:
            dfs(to, cost+1)
dist = [-1]*n
dfs(0, 0)
m = max(dist)
for i in range(n):
    if dist[i] == m:
        start = i
        break
dist = [-1]*n
dfs(start, 0)
m = max(dist)

if m%3==1:
    print("Second")
else:
    print("First")