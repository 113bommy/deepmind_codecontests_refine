k = int(input())
s = list(input())
mod = 10 ** 9 + 7

nagasa = len(s)


ans = pow(26, k, mod)
bunbo = 1
bunshi = 1
for i in range(1, k + 1):
    bunbo *= nagasa - 1 + i
    bunshi *= pow(i, mod - 2, mod)
    bunbo %= mod
    bunshi %= mod
    temp = bunbo * bunshi
    temp %= mod
    temp *= pow(25, i, mod)
    temp %= mod
    temp *= pow(26, k - i, mod)
    temp %= mod
    ans += temp
    ans %= mod

print(ans)
