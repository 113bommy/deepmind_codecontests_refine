def dfs (chain):
    if chain:
        for c in chain:
            if c not in groups:
                groups.add(c)
                dfs(graph[c-1])
            graph[c-1].clear()
graph= [[] for _ in range(int(input()))]; sev = len(graph)
groups,inv,ind = set(),{},1
for _ in range(int(input())):
    u,v = map(int,input().split())
    graph[u-1].append(v)
for i,g in enumerate(graph):
    if g:
        groups.add(i+1)
        dfs(g); inv[ind] = [p for p in groups]
        ind+=1; groups.clear()
graph = [set() for _ in range(sev)]
for f in inv:
    for k in inv[f]: graph[k-1].add(f)
for g in range(sev):
    if not graph[g]: inv[g+1] = [g+1]
for _ in range(int(input())):
    cat = [x for x in map(int,input().split())]
    gat = graph[cat[0]-1].intersection(graph[cat[1]-1])
    if gat:
        for s in cat:
            for l in graph[s-1]:
                try: inv.pop(l)
                except KeyError: continue
if inv: print(len(max(inv.items(),key = lambda x: len(x[1]))[1]))
else: print(0)