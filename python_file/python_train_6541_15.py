n, _ = map(int, input().split())
CST = {} # {c:[[s,t],...]}
for i in range(n):
    s, t, c = map(int, input().split())
    if c in CST: CST[c] += [[s,t]]
    else: CST[c] = [[s,t]]
mx_t = 200002
R = [0]*mx_t
for c, ST in CST.items():
    TZ = [0]*mx_t
    for s,t in ST:
        TZ[2*s - 1] += 1
        TZ[2*t] -= 1
    for i in range(mx_t - 1):
        TZ[i+1] += TZ[i]
        if TZ[i+1] > 0: R[i+1] += 1
print(max(R))
