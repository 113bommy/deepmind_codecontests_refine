n=int(input())
s=[input()for _ in range(n)]
def check(s,t):
  for i in range(n):
    for j in range(n):
      if s[(i+t)%n][j]!=s[(j+t)%n][i]:return False
  return True
ans=0
for i in range(n):
  if check(s,i):ans+=n
print(ans)