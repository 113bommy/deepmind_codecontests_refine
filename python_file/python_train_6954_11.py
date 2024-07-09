import sys
H, W = map(int, input().split())
G = [sys.stdin.readline() for _ in range(H)]

counts = [[[-1] * 4 for _ in range(W + 1)] for _ in range(H + 1)]
for h in range(H):
    for w in range(W):
        if G[h][w] == ".":
            counts[h][w][0] = counts[h][w-1][0] + 1
            counts[h][w][1] = counts[h-1][w][1] + 1
        dih = H - h - 1
        diw = W - w - 1
        if G[dih][diw] == ".":
            counts[dih][diw][2] = counts[dih][diw+1][2] + 1
            counts[dih][diw][3] = counts[dih+1][diw][3] + 1
ans = 0
for h in range(H):
    for w in range(W):
        if G[h][w] == ".":
            ans = max(ans, sum(counts[h][w]) + 1)
print(ans)