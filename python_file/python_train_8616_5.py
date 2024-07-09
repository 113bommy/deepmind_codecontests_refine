K = int(input())
S = input()
N = len(S)
MOD = 10 ** 9 + 7


# 逆元の前計算
factorial = [1, 1]
inverse = [1, 1]
invere_base = [0, 1]
for i in range(2, K + N + 1):
    factorial.append((factorial[-1] * i) % MOD)
    invere_base.append((-invere_base[MOD % i] * (MOD // i)) % MOD)
    inverse.append((inverse[-1] * invere_base[-1]) % MOD)


def nCr(n, r):
    if (r < 0 or r > n):
        return 0
    r = min(r, n - r)
    return factorial[n] * inverse[r] * inverse[n - r] % MOD


ans = 0
for i in range(K + 1):
    ans += pow(25, i, MOD) * nCr(i + N - 1, N - 1) * pow(26, K - i, MOD) % MOD
    ans %= MOD
print(ans % MOD)
