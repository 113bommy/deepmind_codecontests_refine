for xyz in range(0,int(input())):
    x,y=map(int,input().split())
    a,b=map(int,input().split())
    p1=a*(abs(a)+abs(b))
    x,y=min(x,y),max(x,y)
    p2=x*b
    p2+=(abs(x-y))*a
    print(min(p1,p2))