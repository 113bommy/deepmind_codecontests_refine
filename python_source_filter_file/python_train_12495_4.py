n, m, L = map(int, input().split())

a = [list(map(int, input().split())) for _ in range(m)]
b = [list(map(int, input().split())) for _ in range(L)]
c = [[sum(ak * bk for ak, bk in zip(ai,bj)) for bj in zip(*b)] for ai in a]

for ci in c:
    print(*ci)