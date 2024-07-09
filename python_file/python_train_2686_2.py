p = int(input())
aaa = list(map(int, input().split()))

coefs = [0] * p
coefs[0] = sum(aaa)
invs = [pow(x, p - 2, p) for x in range(p + 1)]
for i, a in enumerate(aaa):
    if a == 0:
        continue

    b = 1
    c = 1
    for j in range(p - 1, -1, -1):
        coefs[j] = (coefs[j] - b * c) % p
        b = -b * i % p
        c = c * j * invs[p - j] % p

print(*coefs)
