W,H,x,y,r = list(map(int,input().split())
if (r<=x<=W-r)&(r<=y<=H-y):
    print('Yes')
else:
    print('No')