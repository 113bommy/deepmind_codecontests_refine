N,M,K = map(int,input().split())
fr = [[] for i in range(N+1)]
bl = [[] for i in range(N+1)]
for _ in range(M):
    A,B = map(int, input().split())
    fr[A].append(B)
    fr[B].append(A)
for _ in range(K):
    C,D = map(int, input().split())
    bl[C].append(D)
    bl[D].append(C)

leader = [0]*(N+1)
d = {}
for root in range(1,N+1):
    if leader[root]!=0:
        continue
    d[root] = set([root])
    stack = [root]
    while stack:
        start = stack.pop()
        leader[start] = root
        for v in fr[start]:
            if leader[v]!=0:
                continue
            d[root].add(v)
            stack.append(v)

ans = [0]*(N+1)
for i in range(1,N+1):
    cluster = d[leader[i]]
    ans[i] = len(cluster) - len(fr[i]) - 1
    for b in bl[i]:
        if b in cluster:
            ans[i] -= 1
print(*ans[1:])