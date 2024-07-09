import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
p = list(map(int, input().split()))
xy = []
for _ in range(M):
    xy.append(tuple(map(int, input().split())))
#print(xy)


G = [[] for _ in range(N+1)]
for el in xy:
    x, y = el
    G[x].append(y)
    G[y].append(x)


seen=[False] * (N+1)
def dfs(n):
    seen[n]=True
    group[-1].append(n)
    for child in G[n]:
        if seen[child] == False:
            dfs(child)

group=[]
for i in range(1,N+1):
    if seen[i] == False:
        group.append([])
        dfs(i)
        #print(seen)
#print(seen)
#print(group)

cnt = 0
for el in group:
    temp = set(el) & set([p[i-1] for i in el])
    cnt += len(temp)
print(cnt)
