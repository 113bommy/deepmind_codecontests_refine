for _ in range(int(input())):
    x,y,n=map(int,input().split())
    print(n-(n%x)+y)