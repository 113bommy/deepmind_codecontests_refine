f = lambda: map(int, input().split())
n, s = f()
d = list(f())
t = sum(d)
for q in d: print(q - max(0, min(q, s) - max(0, q - t + s - 1)))