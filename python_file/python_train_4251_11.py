N, M = map(int, input().split())
p = 10**9 + 7

fac = [0] * (N + 33)
inv = [0] * (N + 33)
finv = [0] * (N + 33)

fac[0] = fac[1] = 1
inv[1] = 1
finv[0] = finv[1] = 1

for i in range(2, N+33):
  fac[i] = fac[i-1] * i % p
  inv[i] = p - inv[p%i] * (p // i) % p
  finv[i] = finv[i-1] * inv[i] % p

primes = {}
i = 2
while(M > 1):
  if(M % i == 0):
    primes[i] = primes.get(i, 0) + 1
    M //= i
  else:
    i += 2 - (i + 1) % 2
r = 1
for v in primes.values():
  r = r * fac[N+v-1] * finv[N-1] * finv[v] % p
print(r)