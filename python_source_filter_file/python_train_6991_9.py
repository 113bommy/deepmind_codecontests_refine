x,y,z=map(int,input().split())
if(x>y and x>z):
    print("+")
elif(y>x and y>z):
    print("-")
elif(x==y and z==0):
    print(0)
else:
    print("?")