N, K = map(int, input().split())
A = list(map(int, input().split()))
AS = [0]
for i in range(N):
    AS += [AS[i] + A[i]]
AN = []
for i in range(N):
    for j in range(i, N):
        AN += [AS[j + 1] - AS[i]]
ans = 0
for i in range(41, -1, -1):
    c = 0
    p = ans + 2 ** i
    for x in AN:
        if p & x == p:
            c += 1
    if c >= K:
        ans += 2 ** i
print(ans)
