n=int(input())
A=list(int(input()) for i in range(n))
a=0
for x in range(n):
  a=A[a]-1
  if a==2:
    print(x+2)
    break
else:
  print(-1)