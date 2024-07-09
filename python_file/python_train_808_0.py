N=int(input())
A=[int(c) for c in input().split()]
D=[0 for i in range(60)];
for a in A:
  for i in range(60):
    D[i]+=a%2
    a//=2
t=1
ans=0
for i in range(60):
  ans+=D[i]*(N-D[i])*t
  t*=2
print(ans%1000000007)