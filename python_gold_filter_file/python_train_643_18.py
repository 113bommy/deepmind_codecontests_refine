import math
n,sx,sy = map(int, input().strip().split(' '))
r=0
l=0
u=0
d=0
for i in range(n):
    #n=int(input())
    hx,hy = map(int, input().strip().split(' '))
    if hx>sx:
        r+=1
    if hx<sx:
        l+=1
    if hy>sy:
        u+=1
    if hy<sy:
        d+=1
m=max(u,d,l,r)
if u==m:
    print(u)
    print(sx,sy+1,end=" ")
    print()
elif d==m:
    print(d)
    print(sx,sy-1,end=" ")
    print()
elif l==m:
    print(l)
    print(sx-1,sy,end=" ")
    print()
elif r==m:
    print(r)
    print(sx+1,sy,end=" ")
    print()
    