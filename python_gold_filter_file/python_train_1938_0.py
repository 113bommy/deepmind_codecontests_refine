def dist(i,j):
    return (i**2+j**2)**.5

r,d=map(int,input().split())
count=0
for i in range(int(input())):
    x,y,r1=map(int,input().split())
    d1=dist(x,y)
    if d1+r1<=r and r-d<=d1-r1:
        count+=1
print(count)