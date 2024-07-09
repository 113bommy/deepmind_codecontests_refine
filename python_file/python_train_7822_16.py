n=int(input())
l=list(map(int,input().split()))
x=l[n-1]
c=0
s=""
k=l[0]
j=0
y=0
if(k>x):
    k=x
for i in range(n):
    p=len(l)
    a=l[0+j]
    b=l[p-1-y]
    if a>b:
        c=b
        d=a
    else:
        c=a
        d=b
    if c>=k:
        k=c
        if c==a:
            s=s+"L"
            j+=1
        elif c==b:
            s=s+"R"
            y+=1
    elif d>=k:
        k=d
        if d==a:
            s=s+"L"
            j+=1
        elif d==b:
            s=s+"R"
            y+=1
    else:
        break
j=len(s)
print(j)
print(s)