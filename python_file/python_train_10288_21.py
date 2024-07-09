n = int(input())
x, y, h = [], [], []

for i in range(n):
    X, Y, H = map(int, input().split())
    x.append(X)
    y.append(Y)
    h.append(H)

for X in range(101):
    for Y in range(101):
        for i in range(n):
            H = h[i] + abs(x[i] - X) + abs(y[i] - Y)
            if all(h[j] == max(H - abs(x[j] - X) - abs(y[j] - Y), 0) for j in range(n)):
                print(X, Y, H)
                break