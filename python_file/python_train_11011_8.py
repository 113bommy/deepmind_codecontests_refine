from itertools import accumulate

n, k = map(int, input().split())
a = list(map(int, input().split()))
for _ in range(k):
   b = [0] * n
   for i in range(n):
      b[max(0, i-a[i])] += 1
      tmp = i + a[i] + 1
      if tmp < n:
         b[tmp] -= 1
   a = list(accumulate(b))
   if a == [n] * n:
      break

print(*a)
