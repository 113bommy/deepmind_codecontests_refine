n,m = input().split()
n = int(n)
m = int(m)
ans = 0
for a in range(1000):
    for b in range(1000):
        if a ** 2 + b == n and a + b ** 2 == m:
            ans += 1

print(ans)
