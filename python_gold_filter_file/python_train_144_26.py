n,c=input().split()
n,c=int(n),int(c)
l=[int(x) for x in input().split()]
max1=0
k=0
for i in range(1,len(l)):
    if (l[i-1]-l[i])>max1:
        k=l[i]
        max1=l[i-1]-l[i]
max1=max1+k
if (max1-c-k)>0:
    print(max1-c-k)
else:
    print(0)
