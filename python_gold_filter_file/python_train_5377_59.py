n=int(input())
c=0
if(n%2==0):
    c+=1
if(n%3==0):
    c+=1
if n>3:
    for i in range(4,n+1):
        if(n%i==0):
            c+=1
print(c)