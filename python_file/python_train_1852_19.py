n,x,y=map(int,input().split())
li=[0]*n
for i in range(1,n+1):
  for j in range(1,n+1):
    d=min(abs(i-j),abs(i-x)+abs(j-y)+1,1+abs(i-y)+abs(j-x))
    li[d]+=1
for k in range(1,n):
  print(li[k]//2)