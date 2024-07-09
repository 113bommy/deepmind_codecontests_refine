M=10**9+7
(n,k),*a=[list(map(int,t.split()))for t in open(0)]
r=a if k&1else[[i==j for j in range(n)]for i in range(n)]
d=a
for i in range(1,k.bit_length()):
  p=[]
  for y in d:
    q=[0]*n
    for x,s in zip(y,d):
      for j,t in enumerate(s):
        q[j]+=t*x%M
    p+=q,
  d=p
  if 1<<i&k:
    p=[]
    for y in r:
      q=[0]*n
      for x,s in zip(y,d):
        for j,t in enumerate(s):
          q[j]+=t*x%M
      p+=q,
    r=p
print(sum(t for s in r for t in s)%M)