N, X = map(int, input().split())
A = list(map(int, input().split()))
A.reverse()

acc = [0]
for i in range(0, N):
    acc.append(acc[i] + A[i])

ans = []
for k in range(1, N + 1):
    cost = k * X + N * X
    for i in range(0, (N + k - 1) // k):
        l = k * i
        r = min([l + k, N])
        t = i + 1
        if t == 1:
            cost += (acc[r] - acc[l]) * 5
        else:
            cost += (acc[r] - acc[l]) * (2 * t + 1)
    ans.append(cost)

print(min(ans))