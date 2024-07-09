N,M=map(int, input().split())

if M%N==0:
  print(M//N)
else:
  a=M//N
  while a>0:
    if (M-a*N)%a==0:
      print(a)
      break
    else:
      a-=1