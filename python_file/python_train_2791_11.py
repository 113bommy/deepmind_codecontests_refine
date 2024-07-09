n, k = map(int, input().split())
h = [int(i) for i in input().split()]
dp = [0]
for i in range(1, n):
    to = min(i, k) + 1
    dp += [min([dp[-j] + abs(h[i] - h[i - j]) for j in range(1, to)])]
print(dp[-1])