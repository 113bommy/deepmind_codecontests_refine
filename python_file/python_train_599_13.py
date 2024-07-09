N, S = map(int, input().split())
A = [int(a) for a in input().split()]
X = [0] * 3001
pre = 0
ans = 0
P = 998244353
for i, a in enumerate(A):
    for j in range(S, a, -1):
        X[j] = (X[j] + X[j-a]) % P
    X[a] += i + 1
    ans += (X[S] - pre) * (N - i)
    pre = X[S]
print(ans % P)