a,b,c = map(int,input().split())
if c < a+b and (c-a-b)**2 - 4*a*b >= 0:
    print("Yes")
else:
    print("No")