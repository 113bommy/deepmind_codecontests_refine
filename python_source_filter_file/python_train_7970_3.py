n,k=map(int,input().split())

hour=240-k
i=5
x=1
count=0
while hour>=i:
    hour=hour-i*x
    count+=1
    x+=1
print(n if n>k else count)

