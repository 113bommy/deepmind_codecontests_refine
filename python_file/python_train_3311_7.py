R,G,B,N = map(int,input().split())
ans = 0
for r in range(N//R+1):
  for g in range(N//G+1):
    p = N-(r*R+g*G)
    if p%B==0 and p>=0:
      ans += 1
print(ans)