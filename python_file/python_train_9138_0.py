from collections import deque
N = int(input())
S = [list(map(int, input().strip())) for _ in range(N)]
G = [[] for _ in range(N)]
for i in range(N):
    for j in range(N):
        if S[i][j] == 1:
            G[i].append(j)

#Bipartie Graph
def is_bibarate(G):
    vst = [False] * N
    que = deque([0])
    color = [0] * N
    color[0] = 1
    while len(que):
        p = que.popleft()
        for q in list(G[p]):
            if color[q] == 0:
                color[q] = - color[p]
                que.append(q)
            elif color[q] == color[p]:
                return False
            
    return True
                

        
#Warshal Floyd        
d = [[float('inf')] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if i == j:
            d[i][j] = 0
        elif S[i][j] == 1:
            d[i][j] = 1
            
for k in range(N):
    for i in range(N):
        for j in range(N):
            d[i][j] = min(d[i][j],d[i][k] + d[k][j])

wf_ans = max([max(r) for r in d]) + 1

if is_bibarate(G):
    print(wf_ans)
else:
    print(-1)