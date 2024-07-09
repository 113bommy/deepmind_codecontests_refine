n,m = map(int,input().split())
g = [set() for i in range(n)]
visited = [False] * n
group = []

for i in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    g[a].add(b)
    g[b].add(a)

for i in range(n):
    if visited[i]:
        continue
    s = set()
    q = [i]
    while len(q) > 0:
        p = q.pop()
        visited[p] = True
        s.add(p)
        for x in g[p]:
            if visited[x]:
                continue
            q.append(x)
    group.append(s)

ans = 0
for x in group:
    ans = max(ans, len(x))
print(ans)