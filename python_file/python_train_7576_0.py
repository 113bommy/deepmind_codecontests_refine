import fractions
n = int(input())
a = list(map(int, input().split()))
lcm = a[0]
ans = 0
for i in range(1, n):
    lcm = lcm * a[i] // fractions.gcd(lcm, a[i])
for i in range(0, n):
    ans += lcm//a[i]
print(ans%(10**9+7))