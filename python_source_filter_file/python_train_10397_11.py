n,k=map(int,input().split())
D=list(map(int,input().split()))

for i in range(n,10001):
  for j in str(i):
    if int(j) in D:
      break
  else:
    print(i)
    exit()