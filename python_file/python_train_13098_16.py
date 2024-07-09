from collections import deque
n,m,s,t = map(int,input().split())
edgem = [[]for i in range(n)]
edges = [[]for i in range(n)]
for i in range(m):
    u,v,a,b = map(int,input().split())
    edgem[u-1].append([v-1,a])
    edgem[v-1].append([u-1,a])
    edges[u-1].append([v-1,b])
    edges[v-1].append([u-1,b])

costm = [float('inf')]*n
costs = [float('inf')]*n
costm[s-1],costs[t-1] = 0,0

queue = deque([s-1])
while queue.__len__() > 0:
    p = queue.popleft()
    for a,b in edgem[p]:
        if costm[a] > costm[p] + b:
            costm[a] = costm[p] + b
            queue.append(a)
queue = deque([t-1])
while queue.__len__() > 0:
    p = queue.popleft()
    for a,b in edges[p]:
        if costs[a] > costs[p] + b:
            costs[a] = costs[p] + b
            queue.append(a)
ans = [float('inf')]*n
for i in range(n):
    ans[i] = costm[i] + costs[i]
for i in range(n-1,0,-1):
    ans[i-1] = min(ans[i-1],ans[i])
money = 10**15
for i in ans:
    print(money-i)