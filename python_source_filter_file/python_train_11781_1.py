from math import gcd
def primes():
    yield 2; yield 3; yield 5; yield 7;
    bps = (p for p in primes())             # separate supply of "base" primes (b.p.)
    p = next(bps) and next(bps)             # discard 2, then get 3
    q = p * p                               # 9 - square of next base prime to keep track of,
    sieve = {}                              #                       in the sieve dict
    n = 9                                   # n is the next candidate number
    while True:
        if n not in sieve:                  # n is not a multiple of any of base primes,
            if n < q:                       # below next base prime's square, so
                yield n                     # n is prime
            else:
                p2 = p + p                  # n == p * p: for prime p, add p * p + 2 * p
                sieve[q + p2] = p2          #   to the dict, with 2 * p as the increment step
                p = next(bps); q = p * p    # pull next base prime, and get its square
        else:
            s = sieve.pop(n); nxt = n + s   # n's a multiple of some b.p., find next multiple
            while nxt in sieve: nxt += s    # ensure each entry is unique
            sieve[nxt] = s                  # nxt is next non-marked multiple of this prime
        n += 2                              # work on odds only
 
import itertools
def get_prime_divisors(limit):
    return list(itertools.filterfalse(lambda p: limit % p, itertools.takewhile(lambda p: p <= limit, primes())))
    
n, m = map(int, input().split())
data = {}
for _ in range(m):
    a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)
    x, y = b-a, n-b+a
    if x <= y:
        if x in data:
            data[x].add(a)
        else:
            data[x] = set([a])
    if y <= x:
        if y in data:
            data[y].add(b)
        else:
            data[y] = set([b])

t = n
for s in data.values():
    t = gcd(t, len(s))
    
if t == 1:
    print("No")
else:
    tests = get_prime_divisors(t)
    for k in tests:
        d = n//k
        for s in data.values():
            if any(map(lambda v: (v+d)%n not in s, s)):
                break
        else:
            print("Yes")
            break
    else:
        print("No")
