W,H,x,y,r=map(int,input().split())
if min([x,y]>=r)and x<=(W-r) and y<=(H-r):
    print("Yes")
else:
    print("No")
