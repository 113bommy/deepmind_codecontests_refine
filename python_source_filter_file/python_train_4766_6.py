a,b=list(map(int,input().split()))
if b>=2*a and b<=4*a and b%2==0:
    print('YES')
else:
    print('NO')