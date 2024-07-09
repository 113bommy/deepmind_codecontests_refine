import sys
sys.setrecursionlimit(10**6)
n = int(input())
G = [[] for _ in range(n)]
mod = 10**9 + 7

for _ in range(n-1):
    a,b = map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

stack = [0]
depth = [-1]*n
depth[0] = 0
while stack:
    v = stack.pop()
    d = depth[v]
    for nv in G[v]:
        if depth[nv] >= 0:continue
        depth[nv] = depth[v] + 1
        stack.append(nv)

d_to_i = [[] for _ in range(n)]

for i in range(n):
    d_to_i[depth[i]].append(i)

data = [[] for _ in range(n)]

for d in range(n-1,-1,-1):
    for v in d_to_i[d]:
        for nv in G[v]:
            if depth[nv] < depth[v]:continue
            if data[nv]:
                data[v].append(n-data[nv][-1])
        if data[v]:
            data[v].append(n-1-sum(data[v]))
        else:
            data[v].append(n-1)

ans = 0
two = [1]
for i in range(n):
    two.append(two[-1]*2%mod)
for i in range(n):
    now = two[n-1]-1
    for x in data[i]:
        now -= two[x]-1
        now %= mod
    ans += now

#print(ans)

x = two[n]
x = pow(x,mod-2,mod)
print(ans*x%mod)