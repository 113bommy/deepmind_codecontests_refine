from collections import deque

n,m,k= map(int, input().split())

fri = [[] for _ in range(n+1)]
blo = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    fri[a].append(b)
    fri[b].append(a)

for i in range(k):
    a, b = map(int, input().split())
    blo[a].append(b)
    blo[b].append(a)


gru = [-1] * (n+1)
gru[0] = 0
visited = [False]*(n+1)
D = {}

for root in range(1,n+1):
    if visited[root]:
        continue
    
    D[root]= set([root])
    d = deque()
    d.append(root)
    while d:
        v = d.popleft()
        visited[v] = True
        gru[v] = root
        for to in fri[v]:
            if visited[to]:
                continue
            D[root].add(to)
            d.append(to)


nans = [0]*n
for i in range(1,n+1):
    g = D[gru[i]]
    ans = len(g)-len(fri[i])-1
    for b in blo[i]:
        if b in g:
            ans -= 1
    nans[i-1] = ans

print(*nans, sep='\n')