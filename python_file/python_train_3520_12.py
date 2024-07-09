n = int(input())
*A, = map(int, input().split())
# n = 4
# A = [10, 20, 30, 40]
inf = 10**20
DP = [[None for r in range(n+1)] for l in range(n)]
S = [0]
for i in range(n):
    S.append(S[-1]+A[i])


def f(l, r):
    if r <= l+1:
        DP[l][r] = 0
    if DP[l][r] != None:
        return DP[l][r]
    DP[l][r] = S[r]-S[l]+min([f(l, i)+f(i, r) for i in range(l+1, r)])
    return DP[l][r]


print(f(0, n))
