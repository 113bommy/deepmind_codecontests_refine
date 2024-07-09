R, C, K = map(int, input().split())
V = [[0] * (R + 1) for _ in range(C + 1)]
for _ in range(K):
    r, c, v = map(int, input().split())
    V[c][r] = v

X = [[0] * 4 for _ in range(R + 1)]
for i in range(1, C + 1):
    Vi = V[i]
    for j in range(1, R + 1):
        v = Vi[j]
        Xj = X[j]
        if v:
            Xj[3] = max(Xj[3], Xj[2] + v)
            Xj[2] = max(Xj[2], Xj[1] + v)
            Xj[0] = max(Xj[0], max(X[j-1]))
            Xj[1] = max(Xj[1], Xj[0] + v)
        else:
            Xj[0] = max(Xj[0], max(X[j-1]))

print(max(X[R]))