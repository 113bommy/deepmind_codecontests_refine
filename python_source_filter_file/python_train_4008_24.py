n, w = map(int, input().split())
a = sorted(list(map(int, input().split())))
x = min(a[0], a[-1]/2)
print(min(w, 3 * x * n))