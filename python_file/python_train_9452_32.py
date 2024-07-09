N, M, P = map(int, input().split())
INF = 10**18

edges = []
E = [[] for _ in range(N)]
R = [[] for _ in range(N)]
for _ in range(M):
    fr, to, c = map(int, input().split())
    fr -= 1
    to -= 1
    edges.append((fr, to, -(c - P)))
    E[fr].append(to)
    R[to].append(fr)

def existsPath(s, edges):
    visited = [False] * N
    visited[s] = True
    st = [s]
    while st:
        now = st.pop()
        for to in edges[now]:
            if visited[to]:
                continue
            st.append(to)
            visited[to] = True
    return visited

canGoFrom1 = existsPath(0, E)
canGoFromN = existsPath(N - 1, R)

minDist = [INF] * N
minDist[0] = 0
for i in range(N):
    for fr, to, c in edges:
        d = minDist[fr] + c
        if minDist[to] > d:
            if i == N - 1 and canGoFrom1[fr] and canGoFromN[to]:
                print('-1')
                exit()
            minDist[to] = d

print(max(0, -minDist[N - 1]))
