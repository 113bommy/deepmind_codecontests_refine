W,H,x,y,r =map(int,input().split())

if (r<=x and x+r<W and r<=y and y+r<=H):
  print("Yes")
else:
  print("No")
 
