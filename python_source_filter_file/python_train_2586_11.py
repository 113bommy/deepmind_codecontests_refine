n = int(input())
a = [int(input()) for _ in range(n)]
s = a[0]
c = 1
while s == 2 and c<n:
    s = a[s-1]
    c += 1
print(c if c<n else -1)
