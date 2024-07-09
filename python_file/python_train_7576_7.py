import fractions
n = int(input())
al = list(map(int,input().split()))
al = sorted(al)
p = al[0]
for i in range(1, n):
    p = p * al[i] // fractions.gcd(p, al[i])

ans = 0

for a in al:
    ans += p // a

print(ans % (10**9 + 7))
