for _ in range(int(input())):
    a,b=map(int,input().split())
    if a<2:
        print("0")
    elif a==2:
        print("b")
    else:
        print(2*b)
        