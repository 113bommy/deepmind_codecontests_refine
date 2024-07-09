n, k = map(int, input().split())
P = [*map(lambda x: int(x)-1, input().split())]
C = [*map(int, input().split())]

INF = 10**18
max_score = -INF
for st in range(n):
    lc = 0 # lap count
    lap_sc = 0 # lap score
    nx = st
    while True:
        lc += 1
        lap_sc += C[nx]
        nx = P[nx]
        if nx == st: break

    lap_sc = max(0, lap_sc)
    sum_sc = 0
    kc = 0
    while True:
        kc += 1
        if k < kc: break
        sum_sc += C[nx]
        score = sum_sc + lap_sc * ((k - kc) // lc)
        max_score = max(max_score, score)
        nx = P[nx]
        if nx == st: break

print(max_score)
