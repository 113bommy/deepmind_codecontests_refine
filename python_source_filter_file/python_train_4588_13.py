while True:
    n,x=map(int,input().split())
    if n==0 and x==0:break
    ans =0
    for a in range(1,n+1):
        for b in range(1,n+1):
            if b<=a:continue
            c=x-(a+b)
            if c>b and c<=n:ans+1
    print("%d"%(ans))

