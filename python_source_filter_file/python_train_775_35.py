a=input().split()
x=int(a[0])
y=int(a[1])
p=int(a[2])
q=int(a[3])
m=0
n=0
r=min(p,q)
while(x>0 and y>0):
    x=x-r
    if(x<=0):
        break
    m=m+1
    y=y-r
    if(y<=0):
        break
    n=n+1
if(m>n):
    print("First")
else:
    print("Second")