N, C = map(int, input().split())
STC = [[*map(int, input().split())] for _ in range(N)]
mx_t = 200002
R = [0]*mx_t
for cc in range(1, C+1):
    TZ = [0]*mx_t
    for s,t,c in STC:
        if c == cc:
            TZ[2*s - 1] += 1
            TZ[2*t] -= 1
    for i in range(mx_t - 1):
        TZ[i+1] += TZ[i]
        if TZ[i+1] > 0: R[i+1] += 1
print(max(R))

