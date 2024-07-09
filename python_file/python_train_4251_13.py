N, M = map(int, input().split())

# 階上の計算
from math import factorial
from collections import defaultdict

def prime_decomposition(n):
  i = 2
  table = defaultdict(int)

  while i * i <= n:
    while n % i == 0:
      n /= i
      table[i] += 1
    i += 1

  if n > 1:
    table[n] += 1

  return list(table.values())


def nHr(n, r):
    return factorial(n+r-1) // (factorial(r) * factorial(n-1))


mod = 10 ** 9 + 7

ans = 1

prim_d_num = prime_decomposition(M)

for p in prim_d_num:
    ans *= nHr(p+1, N-1)

print(ans % mod)
