N,M,P = map(int,input().split())
ABC = [tuple(map(int,input().split())) for i in range(M)]

g = [[] for i in range(N)]
revg = [[] for i in range(N)]

for a,b,_ in ABC:
    a,b = a-1, b-1
    g[a].append(b)
    revg[b].append(a)

st = set([0])
stack = [0]
while stack:
    v = stack.pop()
    for to in g[v]:
        if to in st: continue
        st.add(to)
        stack.append(to)

revst = set([N-1])
stack = [N-1]
while stack:
    v = stack.pop()
    for to in revg[v]:
        if to in revst: continue
        revst.add(to)
        stack.append(to)

use = st & revst
es = []
for a,b,c in ABC:
    a,b = a-1, b-1
    if a in use and b in use:
        es.append((a,b,c))

INF = float('inf')
d = [INF] * N
d[0] = 0
for i in range(N):
    for fr,to,c in es:
        cost = -(c-P)
        if d[to] > d[fr]+cost:
            d[to] = d[fr] + cost
            if i == N-1:
                print(-1)
                exit()

print(max(0,-d[-1]))