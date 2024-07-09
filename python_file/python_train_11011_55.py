n,k,*A=map(int,open(0).read().split());e=enumerate
for _ in '_'*min(k,99):
  S=[0]*(n+1)
  B=[0]*(n+1)
  for i,a in e(A):S[max(0,i-a)]+=1;S[min(n,i+a+1)]-=1
  for i,s in e(S[:-1]):B[i+1]=B[i]+s
  A=B[1:]
print(*A)