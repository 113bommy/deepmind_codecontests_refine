N, M = map(int, input().split())
G = [[] for _ in range(3 * N)]
L = [-3 for _ in range(3 * N)]
for _ in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    G[3*u+0].append(3*v+1)
    G[3*u+1].append(3*v+2)
    G[3*u+2].append(3*v+0)
s, t = map(int, input().split())
S = 3 * (s-1)
T = 3 * (t-1)

L[S] = 0
Frontier = [S]
while Frontier:
    v = Frontier.pop(0)
    for i in G[v]:
        if L[i] < 0:
            Frontier.append(i)
            L[i] = L[v] + 1

print(L[T]//3)