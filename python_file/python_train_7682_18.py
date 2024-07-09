import sys
from math import factorial

input = sys.stdin.readline

Mod = 10**9 + 7


def Cmb(n, k):
    return factorial(n) // (factorial(n - k) * factorial(k)) % Mod


n, m, k = list(map(int, input().split()))

ans = 0

for i in range(1, n + 1):
    ans += i * (n - i) * m**2 % Mod

for i in range(1, m + 1):
    ans += i * (m - i) * n**2 % Mod

ans *= Cmb(n * m - 2, k - 2)
ans %= Mod

print(ans)
