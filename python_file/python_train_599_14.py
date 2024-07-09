MOD = 998244353

N, S = map(int, input().split())
A = list(map(int, input().split()))

F = [0 for _ in range(S + 1)]
res = 0

for i in range(N):
    F[0] += 1
    for j in range(S + 1)[::-1]:
        if j - A[i] >= 0:
            F[j] += F[j - A[i]]
    res += F[S]
    res %= MOD

print(res)