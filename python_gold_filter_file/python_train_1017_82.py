n,k,s=map(int,input().split())

A=[s]*k
for i in range(len(A),n):
  if s!=10**9:
    A.append(s+1)
  else:
    A.append(1)
print(*A)
  