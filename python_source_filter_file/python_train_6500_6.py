n=int(input())
a=list(map(int,input().split()))
b=sorted(a)
c=[0]
d=[0]
s1=0
s2=0
for i in range(n):
    s1+=a[i]
    s2+=b[i]
    c.append(s1)
    d.append(s2)
for i in range(int(input())):
    typ,l,r=map(int,input().split())
    if (typ==1):
        print(c[r]-c[l-1])
    else:
        print(d[r]-d[r-1])