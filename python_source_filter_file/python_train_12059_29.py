N, M = map(int, input().split())

if N == 1 and M == 1:
    print(1)

if N == 1 or M == 1:
    print(max(N - 2, M - 2))
else:
    print((N - 2) * (M - 2))
