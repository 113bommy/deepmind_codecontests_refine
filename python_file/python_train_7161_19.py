n, t = map(int, input().split())
dishes = []

for _ in range(n):
    time, point = map(int, input().split())
    dishes.append([time, point])

dishes.sort()

DP = [0] * t

candidates = []
for time, point in dishes:
    candidates.append(max(DP) + point)

    for i in range(t-1, time-1, -1):
        DP[i] = max(DP[i], DP[i-time]+point)

print(max(candidates))