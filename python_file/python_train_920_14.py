N, x = map(int,input().split())
a = list(map(int,input().split()))

inf = float('inf')
ans = inf

time = [[inf] * N for _ in range(N)]

for i in range(N):
    tmp = inf
    for k in range(N):
        ni = i + k
        if ni > N - 1:
            ni %= N
        tmp = min(tmp, a[ni])
        time[i][k] = tmp

# k回魔法を唱える
for k in range(N):
    res = k*x
    for i in range(N):
        res += time[i][k]
    ans = min(ans, res)

print(ans)