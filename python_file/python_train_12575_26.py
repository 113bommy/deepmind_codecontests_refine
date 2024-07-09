n = int(input())
s = input()

mx = 0
for i in range(1, n):
    t = 0
    for j in range(n - i):
        t = t + 1 if s[j] == s[j + i] else 0
        mx = max(mx, min(i, t))

print(mx)