n = int(input())
A = list(map(int, input().split()))
ans = 0
for j in range(61):
  c = 0
  for i in A:
    if i>>j & 1:
      c += 1
  ans += 2**j*((n-c)*c)
print(ans%(10**9+7))