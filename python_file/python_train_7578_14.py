def f(n):
  a=[];f=2
  while f*f<=n:
    if n%f==0:a.append(f);n//=f
    else:f+=1
  if n!=1:a.append(n)
  return set(a)
s=[2];n=int(input())
for L in range(3,n+1):
  c=True
  for M in s:
    if L%M==0:c=False
  if c==True:s.append(L)
A=[int(input())for i in range(n+1)]
P=sorted(list(set(s)|f(abs(A[0]))))
for p in P:
  B=A[0:n+2];b=0
  for j in range(n+1):
    if p+j<n+1:B[j+p-1]=(B[j+p-1]+B[j])%p
    elif B[j]%p!=0:b=1;break
  if b==0:print(p)