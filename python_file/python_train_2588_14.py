from itertools import product

H, W, N = map(int, input().split())
V = set([tuple(map(int, input().split())) for _ in range(N)])
D = tuple(product((-1, 0, 1), repeat=2))

A = set()
for a, b in V:
    for h, w in D:
        if 2 <= a + h <= H - 1 and 2 <= b + w <= W - 1:
            A.add((a + h, b + w))

ans = [0] * 10
for a, b in A:
    cnt = 0
    for h, w in D:
        if (a + h, b + w) in V:
            cnt += 1
    ans[cnt] += 1

ans[0] = (H - 2) * (W - 2) - sum(ans)
print(*ans, sep='\n')
