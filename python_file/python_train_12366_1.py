H, W, K = map(int,input().split())
S = [list(map(int,input())) for _ in range(H)]
ans = float("inf")
for i in range(1<<(H - 1)):
    data = [S[0][0:]]
    for j in range(H - 1):
        if (i >> j) & 1:
            data.append([0] * W)
        for k in range(W):
            data[-1][k] += S[j + 1][k]
    if any([any([x > K for x in y]) for y in data]):
        continue
    cnt = len(data) - 1
    judge = [0] * len(data)
    for j in range(W):
        if any([judge[x] + data[x][j] > K for x in range(len(data))]):
            judge = [0] * len(data)
            cnt += 1
        judge = [judge[x] + data[x][j] for x in range(len(data))]
    ans = min(ans, cnt)
print(ans)