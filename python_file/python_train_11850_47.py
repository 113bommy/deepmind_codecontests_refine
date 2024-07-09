N, M = map(int, input().split())

X = M // N
for x in range(X, 1, -1):
    r = M - x * (N - 1)
    if r % x == 0:
        print(x)
        exit()
print(1)