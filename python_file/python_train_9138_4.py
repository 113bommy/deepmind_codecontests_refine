def warshall_floyd(g):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])

n = int(input())
s = [[int(i) for i in list(input())] for _ in range(n)]
graph = [[float("inf")]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if s[i][j] == 1:
            graph[i][j] = 1
        if i == j:
            graph[i][j] = 0

warshall_floyd(graph)
d = 0
#print(graph)
for i in range(n-1):
    for j in range(i+1,n):
        if graph[i][j] != float("inf"):
            if d < graph[i][j]:
                start = i
                end = j
                d = graph[i][j]

v = [[] for _ in range(d+1)]
for i in range(n):
    l = graph[start]
    v[l[i]].append(i)
#print(v)
#print(start,end)

for l in v:
    m = len(l)
    for i in range(m-1):
        for j in range(i+1,m):
            if s[l[i]][l[j]] == 1:
                print(-1)
                quit()
print(d+1)