n=int(input())
mat=[[0]*30 for _ in range(30)]
ary=[]
op=0
a=[]
for _ in range(n):
  t=list(input().split('.'))
  if len(t)==1:
    c=int(t[0])*pow(10,9)
  else:
    c=int(t[0])*pow(10,9)
    r=int((t[1]+'0'*10)[:9])
    c+=r
  n2,n5=0,0
  while (c//pow(2,n2))%2==0:
    n2+=1
  while (c//pow(5,n5))%5==0:
    n5+=1
  n2=min(n2,9+9)
  n5=min(n5,9+9)
  mat[n2][n5]+=1
  a.append((c,n2,n5))
  ary.append((n2,n5))
#for x in a:
#  print(x)
summat=[[0]*31 for _ in range(31)]
for i in range(30):
  for j in range(30):
    summat[i+1][j+1]=summat[i+1][j]+mat[i][j]
for i in range(30):
  for j in range(30):
    summat[i+1][j+1]+=summat[i][j+1]

ans=0
for n2,n5 in ary:
  t2,t5=n2,n5
  t2-=9
  t2*=-1
  t2+=9
  t5-=9
  t5*=-1
  t5+=9
  #print(n2,n5,t2,t5)
  ans+=summat[-1][-1]-summat[t2][-1]-summat[-1][t5]+summat[t2][t5]
  if n2>=9+op and n5>=9+op:ans-=1
print(ans//2)
