a,b,x=map(int,input().split())
if(a>=b):
    if(x%2==0):print("01"*(x//2)+"1"*(b-x//2)+"0"*(a-x//2))
    elif(x==1):print("0"*a+"1"*b)
    else:print("0"*(a-x//2-1)+"01"*(x//2+1)+"1"*(b-x//2-1))   
else:
    if(x%2==0):print("10"*(x//2)+"0"*(a-x//2)+"1"*(b-x//2))
    elif(x==1):print("1"*b+"0"*a)
    else:print("1"*(a-x//2-1)+"10"*(x//2+1)+"0"*(b-x//2-1))  