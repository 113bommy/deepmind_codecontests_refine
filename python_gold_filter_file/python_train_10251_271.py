n = int(input())

if(n%2==0):
    print(( (n//2)**2+(n//2) ) - (n//2)**2)
else:
    print(( (n//2)**2 + (n//2)) - ((n//2) +1)**2 )