n,m,k=map(int,input().split())
for i in range(n+1):
  for j in range(m+1):
    s=n*i+m*j-2*i*j
    if s==k:
      print("Yes")
      exit()
print("No")