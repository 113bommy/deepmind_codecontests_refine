[x1,y1] = map(int, input().split())
[x2,y2] = map(int, input().split())
x2=abs(x2-x1)
y2=abs(y2-y1)
if x2>y2:
    print(x2)
else:
    print (y2)