N=int(input())
d=list(map(int,input().split()))
s=0
for i in range(0,N):
  s+=d[i]*sum(d[i+1:N])
print(s)