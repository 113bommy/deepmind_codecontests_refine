t=int(input())
while t:
    t-=1
    n=int(input())
    if n%2==0:
        print(int(n/2)+1)
    else:
        print(int((n-1)/2) +1)
