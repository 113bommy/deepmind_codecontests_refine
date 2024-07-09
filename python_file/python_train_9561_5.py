n, k = map(int, input().split())
graph = []
Y = []
X = []
for _ in range(n):
    x, y = map(int, input().split())
    graph.append([x, y])
    Y.append(y)
    X.append(x)

Y.sort()
X.sort()
ans = []
for sx in range(n):
    for ex in range(n-1, sx, -1):
        for sy in range(n):
            for ey in range(n-1, sy, -1):
                x1, x2, y1, y2 = X[sx], X[ex], Y[sy], Y[ey]
                count = len([True for x, y in graph if x1 <= x <= x2 and y1 <= y <= y2])
                if count >= k:
                    ans.append((x2-x1)*(y2-y1))
                else:
                    break

print(min(ans))