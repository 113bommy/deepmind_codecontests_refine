def gh(w):
    return (w*(w+1))//2
a,b=map(int,input().split())
z=a-1
r=min(b,a//2)
f=gh(z)
k=max(0,z-2*r)
l=gh(k)
if b<=r:print(f-l)
else:print(max(0,f-l-(r-b)%2))