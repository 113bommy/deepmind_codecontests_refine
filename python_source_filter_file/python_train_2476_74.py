a,b,c,d=map(int,input().split())
x=(a+d-1)/d
y=(c+b-1)/b
if x>=y:
    print('Yes')
else:
    print('No')
