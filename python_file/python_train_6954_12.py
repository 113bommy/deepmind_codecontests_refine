h, w = map(int, input().split())
s = [input() for _ in range(h)]
a = [[None] * w for _ in range(h)]
for i in range(h):
    p = 0
    while p < w:
        j = p
        while j < w and s[i][j] == '.':
            j += 1
        for k in range(p, j):
            a[i][k] = j - p
        p = j + 1
r = 0
for j in range(w):
    p = 0
    while p < h:
        i = p
        while i < h and s[i][j] == '.':
            i += 1
        for k in range(p, i):
            r = max(r, a[k][j] + i - p - 1)
        p = i + 1

print(r)
