while 1:
    n,x=map(int,input().split())
    if n == 0 and x == 0: break
    print(len([1 for a in range(1,n+1), for b in range(a+1,n+1), for c in range(b+1,n+1), a + b + c == x]))