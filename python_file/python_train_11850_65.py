n, m = list(map(int, input().split()))
ans = m//n
while m%ans!=0:
  ans -= 1
print(ans)