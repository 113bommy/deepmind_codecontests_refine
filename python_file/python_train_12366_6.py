from itertools import product

H, W, K = map(int, input().split())
S = [[int(i) for i in input()] for _ in range(H)]

T = [t for t in zip(*S)]
if sum(map(sum, T)) <= K:
    print(0)
    quit()

ans = float("inf")
for P in product([0, 1], repeat=H - 1):
    cnt = sum(P)

    II = [[0]]
    for i, p in enumerate(P, 1):
        if p:
            II.append([])
        II[-1].append(i)

    A = [0] * len(II)
    for t in T:
        for i, I in enumerate(II):
            A[i] += sum(t[x] for x in I)

        if any(a > K for a in A):
            cnt += 1
            if cnt >= ans:
                break

            A = [sum(t[x] for x in I) for I in II]
            if any(a > K for a in A):
              cnt = 1 + ans
              break

    ans = min(ans, cnt)

print(ans)