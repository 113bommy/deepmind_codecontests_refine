n=int(input())
a=list(map(int,input().split()))
s=sum(a)
new=0
i=0
while 2*(new+a[i])<s:
    new+=a[i]
    i+=1
print(i+1)
