n,k=map(int,input().split())
x,y,xy=[],[],[]
for _ in range(n):
  a,b=map(int,input().split())
  x.append(a)
  y.append(b)
  xy.append((a,b))
x.sort()
y.sort()
ans=float('inf')
for i in range(n-1):
  x1=x[i]
  for j in range(i+1,n):
    x2=x[j]
    for l in range(n-1):
      y1=y[l]
      for m in range(l+1,n):
        y2=y[m]
        cnt=0
        for o in range(n):
          x3,y3=xy[o]
          if x1<=x3<=x2 and y1<=y3<=y2:
            cnt+=1
        if cnt>=k:
          ans=min(ans,(x2-x1)*(y2-y1))
print(ans)