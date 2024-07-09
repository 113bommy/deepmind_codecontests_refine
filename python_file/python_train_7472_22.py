def f(s):
  m=0
  n=0
  for i in s:
    if i==")":n-=1
    else:n+=1
    m=min(m,n)
  return [m,n]
n=int(input())
s=[input()for _ in range(n)]
mab=[]
pab=[]
for i in range(n):
  ab=f(s[i])
  if sum(ab)>0:pab.append(ab)
  else:mab.append(ab)
pab.sort(reverse=1)
mab.sort(key=lambda x:x[0]-x[1])
#print(pab)
#print(mab)
ab=pab+mab
n=0
for a,b in ab:
  if n+a<0:exit(print("No"))
  n+=b
  if n<0:exit(print("No"))
if n==0:print('Yes')
else:print('No')