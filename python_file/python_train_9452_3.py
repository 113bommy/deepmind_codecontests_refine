N, M, P = map(int, input().split())

edges = []
toE = [[] for _ in range(N)]
frE = [[] for _ in range(N)]
for _ in range(M):
    fr, to, c = map(int, input().split())
    fr -= 1
    to -= 1
    edges.append((fr, to, -(c - P)))
    toE[fr].append(to)
    frE[to].append(fr)

def getVisitedList(s, edges):
    visited = [False] * N
    st = [s]
    visited[s] = True
    while st:
        now = st.pop()
        for to in edges[now]:
            if not visited[to]:
                visited[to] = True
                st.append(to)
    return visited

canGo = getVisitedList(0, toE)
canBack = getVisitedList(N - 1, frE)

def sol():
    minDist = [10**18] * N
    minDist[0] = 0
    for i in range(N + 1):
        for fr, to, c in edges:
            d = minDist[fr] + c
            if minDist[to] > d:
                if i == N and canGo[fr] and canBack[to]:
                    return -1
                minDist[to] = d
    return max(0, -minDist[N - 1])

print(sol())
