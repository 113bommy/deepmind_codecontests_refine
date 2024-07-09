r,g,b,n = map(int,input().split())
ans = 0

for i in range(n + 1):
  for j in range(n + 1):
    tmp = n - i*r - j*g
    if tmp >= 0 and tmp%b == 0:
      ans += 1

print(ans)
