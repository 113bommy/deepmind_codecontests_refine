s=input()
a=[0]*13
a[0]=1
for i in s:
  b=[0]*13
  for j,k in enumerate(a):
    b[(j*10)%13]+=k
  a=b[:]
  b=[0]*13
  if i=="?":
    for l in range(10):
      for j,k in enumerate(a):
        b[(j+l)%13]+=k
  else:
    for j,k in enumerate(a):
      b[(j+int(i))%13]+=k
  a=[j%(10**9+7) for j in b]
print(a[5]%(10**9+7))