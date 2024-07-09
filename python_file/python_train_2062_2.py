N, M = map(int, input().split())
v = set()


def dfs(graph, start, visited):
    stack = [start]
    visited.add(start)
    while stack:
        label = stack.pop(0)
        for node in g[label]:
            if node not in visited:
                visited.add(node)
                stack.append(node)
    return visited


g = {i: [] for i in range(1, N + 1)}
for i in range(M):
    x, y, z = map(int, input().split())
    g[x].append(y)
    g[y].append(x)
ans = 0
for i in range(1, N + 1):
    if i not in v:
        ans += 1
        dfs(g, i, v)
print(ans)