def prepare(n, MOD):
    f = 1
    factorials = [1]
    for m in range(1, n + 1):
        f *= m
        f %= MOD
        factorials.append(f)
    inv = pow(f, MOD - 2, MOD)
    invs = [1] * (n + 1)
    invs[n] = inv
    for m in range(n, 1, -1):
        inv *= m
        inv %= MOD
        invs[m - 1] = inv
    return factorials, invs


k = int(input())
s = input()
l = len(s)
MOD = 10 ** 9 + 7

facts, finvs = prepare(k + l, MOD)

ans = 0
for i in range(k + 1):
    r = k - i
    pat = facts[l + r - 1] * finvs[l - 1] * finvs[r] % MOD
    ans = (ans + pat * pow(25, r, MOD) * pow(26, i, MOD)) % MOD
print(ans)
