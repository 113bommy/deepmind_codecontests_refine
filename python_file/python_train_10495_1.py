import queue
H, W = map(int, input().split())
S = [list(map(int, input().replace(".", "0").replace("#","1"))) for h in range(H)]

Search = [(-1, 0), (0, -1), (1, 0), (0, 1)]
Total = 0
Visited = [[False for w in range(W)] for h in range(H)]
for h in range(H):
    for w in range(W):
        if not Visited[h][w]:
            Visited[h][w] = True
            Color = ([1, 0] if S[h][w] == 0 else [0, 1])
            Q = queue.Queue()
            Q.put((h, w, S[h][w]))
            while not Q.empty():
                nh, nw, nc = Q.get()
                for s in Search:
                    nexth, nextw = nh + s[0], nw + s[1]
                    if 0 <= nexth < H and 0 <= nextw < W:
                        if not Visited[nexth][nextw] and S[nexth][nextw] != nc:
                            nextc = S[nexth][nextw]
                            Visited[nexth][nextw] = True
                            Q.put((nexth, nextw, nextc))
                            Color[nextc] += 1
            Total += Color[0] * Color[1]

print(Total)