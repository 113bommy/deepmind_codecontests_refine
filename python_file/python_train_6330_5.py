mod = 998244353
N = int(input())
A = [int(input()) for i in range(N)]
A.sort()
S = sum(A)

PS = [0 for i in range(N+1)]
for i in range(N):
    PS[i+1] = PS[i] + A[i]

# D[i][r]: i個塗った時点でR=rとなる場合の数
D = [[0 for _ in range(PS[i]+1)] for i in range(N+1)]
D[0][0] = 1
# D2[i][r]: i個塗った時点でR=r, B=0となる場合の数
D2 = [[0 for _ in range(PS[i]+1)] for i in range(N+1)]
D2[0][0] = 1

for i in range(N):
    for j in range(PS[i]+1):
        if D[i][j] == 0:
            continue
        D[i+1][j] = (D[i+1][j] + D[i][j] * 2) % mod
        D[i+1][j+A[i]] = (D[i+1][j+A[i]] + D[i][j]) % mod

for i in range(N):
    for j in range(PS[i]+1):
        if D2[i][j] == 0:
            continue
        D2[i+1][j] = (D2[i+1][j] + D2[i][j]) % mod
        D2[i+1][j+A[i]] = (D2[i+1][j+A[i]] + D2[i][j]) % mod

border = (S + 1) // 2

result = 3 ** N
result -= 3 * sum(D[N][border:])
if border * 2 == S:
    result += 3 * D2[N][border]

print(result % mod)
