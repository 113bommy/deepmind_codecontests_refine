n = int(input())

if n==3:
    print(6)
elif n == 2:
    print(2)
elif n==1:
    print(1)
elif n%2==0:
    
    if n%3==0:
        print((n-1)*(n-2)*(n-3))
    else:
        print((n)*(n-1)*(n-2))
else:
    print((n)*(n-1)*(n-2))