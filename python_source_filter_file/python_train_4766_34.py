a, b = map(int, input().split())
if b>=2*a and b<=4*a and a%2==0:
    print('Yes')
else:
    print('No')
