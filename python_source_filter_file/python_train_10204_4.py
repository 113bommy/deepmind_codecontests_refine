N = int(input())
a = list(map(int, input().split()))
print(*a)
for i in range(1, N):
  v = a[i]
  j = i - 1
  while j >= 0 and a[j] > v:
    a[j + 1] = a[j]
    j -= 1
    a[j + 1] = v
    print(*a)