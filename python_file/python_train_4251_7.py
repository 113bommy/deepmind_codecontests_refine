import math


def combinations_with_replacement_count(n, r):
    return math.factorial(n + r - 1) // (math.factorial(n - 1) * math.factorial(r))


nm = list(map(int, input().split()))
n = nm[0]
m = nm[1]
fact = {}
i = 2
while i * i <= m:
    while m % i == 0:
        m = m // i
        if i in fact:
            fact[i] += 1
        else:
            fact[i] = 1
    i += 1
if m > 1:
    fact[m] = 1
j = 2
ans = 1
for k in fact:
    ans = ans * combinations_with_replacement_count(n, fact[k])
print(ans % (10 ** 9 + 7))
