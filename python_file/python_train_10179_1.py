n=int(input())
r=range(1,int(2*n**.5)+1)
l=[0]*-~n
for i in r:
  for j in r:
    for k in r:
      t=(j+k)**2+(k+i)**2+(i+j)**2
      if t<=n*2 and t%2<1: l[t//2]+=1
for i in range(n): print(l[i+1])