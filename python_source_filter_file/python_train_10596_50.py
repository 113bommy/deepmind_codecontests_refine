n,k = map(int, input().split())
ans = 0
while n > k**ans:
  ans += 1
print(ans)