N=int(input())
for n in range(1,3501):
  for h in range(1,3501):
    a=N*n*h
    b=4*n*h-N*(n+h)
    if b>0 and a%b==0:
      w=a//b
      print(n,h,w)
      exit()