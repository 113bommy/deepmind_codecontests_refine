n, t = map(int, input().split())
f = [[0, 0] for i in range(t + 1)]
for i in range(n):
  w, v = map(int, input().split())
  for j in range(t, 0, -1):
    f[j][1] = max(f[j][1], f[j - 1][0] + v)
    if j >= w:
      f[j][0] = max(f[j][0], f[j - w][0] + v)
      f[j][1] = max(f[j][1], f[j - w][1] + v)
print(f[t][1])