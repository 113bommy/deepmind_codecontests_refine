I=lambda:[int(i)for i in input().split()]
n,m=I()
P=I()
D={i:i for i in range(n)}
def U(x):
  if D[x]!=x:
    D[x]=U(D[x])
  return D[x]
for _ in [0]*m:
  x,y=I();D[U(x)]=U(y)
print(sum(U(i-1)==U(p)for i,p in enumerate(P)))

