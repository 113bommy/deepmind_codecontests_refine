for t in range(int(input())):
    n,m=map(int,input().split())
    if (n%m)%m==0:
        print("YES")
    else:
        print("NO")