a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())
if e>f:
    tot=0
    x=min(a,d)
    d-=x
    tot+=x*e
    a=min(b,c,d)
    tot+=a*f
    print(tot)
else:
    tot=0
    x=min(b,c,d)
    d-=x
    tot+=x*f
    print(tot+e*min(a,d))
    
