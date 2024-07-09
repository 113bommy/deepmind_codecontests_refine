n, k = map(int, input().split())
a = list(map(int, input().split()))

while min(a) < n and k > 0:
  mark = [0] * (n + 1)
  for i in range(n):
    mark[max([0, i - a[i]])] += 1
    mark[min([n, i + a[i] + 1])] -= 1
  a = [mark[0]]
  for i in range(1, n):
    a.append(a[-1] + mark[i])
  k -= 1

print(' '.join(map(str, a)))