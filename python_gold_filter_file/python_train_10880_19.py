n=int(input())
if(n%2==0):
    if(n%4==0):
        print((n//4)-1)
    else:
        print(n//4)
else:
    print(0)
