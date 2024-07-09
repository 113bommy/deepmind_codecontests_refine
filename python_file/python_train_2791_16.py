n, k = map(int, input().split())
h = list(map(int, input().split()))
a = [0] * n
a[0] = 0
for i in range(1, n):
      hi = h[i]
      a[i] = min(a[j] + abs(hi - h[j]) for j in range(max(0, i - k), i))
print(a[-1])