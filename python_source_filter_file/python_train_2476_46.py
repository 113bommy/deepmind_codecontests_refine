a,b,c,d=map(int,input().split())
x=int((a+d-1)/d)
y=int((c+b-1)/c)
 
if x>=y:
  print("Yes")
else:
  print("No")
