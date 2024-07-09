def par(a):
    L = []
    while P[a] != a:
        L.append(a)
        a = P[a]
    for l in L:
        P[l] = a
    return a
def unite(a, b):
    pa = par(a)
    pb = par(b)
    if pa == pb: return
    if LEN[pa] < LEN[pb]:
        a, b, pa, pb = b, a, pb, pa
    P[pb] = pa
    if LEN[pa] == LEN[pb]: LEN[pa] += 1
    CNT[pa] += CNT[pb]
def cnt(a):
    return CNT[par(a)]

N = int(input())
P = [i for i in range(N)]
LEN = [1] * N
CNT = [1] * N
FULL = [0] * N
A = [int(a) - 1 for a in input().split()]
for i, a in enumerate(A):
    if a < 0: continue
    if par(i) != par(a):
        unite(i, a)
    else:
        FULL[i] = 1
for i in range(N):
    if FULL[i]:
        FULL[par(i)] = 1
X = []
Y = []
for i in range(N):
    if par(i) == i:
        if FULL[i] == 0:
            X.append(CNT[i])
        else:
            Y.append(CNT[i])
M = len(X)
mod = 10 ** 9 + 7
K = 96
m = int(("1" * 32 + "0" * 64) * 5050, 2)
pa = (1 << 64) - ((1 << 64) % mod)
modP = lambda x: x - ((x & m) >> 64) * pa
ans = (sum(X) + sum(Y) - len(Y)) * pow(N - 1, M, mod) % mod
x = 1
for i, a in enumerate(X):
    x *= (a << K) + 1
    x = modP(x)

sx = bin(x)[2:] + "_"
L = [int(sx[-(i+1) * K - 1:-i * K - 1], 2) % mod for i in range((len(sx)+K-2) // K)]
fa = 1
ans = (ans + M * pow(N - 1, M - 1, mod)) % mod
for i, l in enumerate(L):
    if i == 0: continue
    ans = (ans - l * fa * pow(N - 1, M - i, mod)) % mod
    fa = fa * i % mod
print(ans)