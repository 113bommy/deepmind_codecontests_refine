n,s=map(int, input().split())
f=[]
maxi=0
c=0
for index in range(n):
    x,y=map(int,input().split())
    f.append([x,y])
    if maxi<x+y:
        maxi=x+y
print(maxi)
    