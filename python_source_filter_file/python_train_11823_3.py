a,b,c=[int(x) for x in input().split()]
k=max(a,b,c)
if(k==a):
    d=max(b,c)
elif(k==b):
    d=max(a,c)
else:
    d=max(a,b)
print(d)
s=abs(a-d)+abs(b-d)+abs(c-d)
print(s)