f=lambda:map(int,input().split())
a,b=f()
print([2,a][b%a==0])