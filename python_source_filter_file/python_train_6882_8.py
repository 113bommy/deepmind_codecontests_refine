n=int(input())
if n<10:
    print(n)
else:
    l=len(str(n))-1
    p=int('9'*1)
    t=n-p
    s=0
    while(t>0):
        s+=t%10
        t//=10
    print(s+9*l)