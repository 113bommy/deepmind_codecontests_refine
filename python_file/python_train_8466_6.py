n,c = map(int,input().split())
from sys import stdin
lst,q = [],0
for i in range(n):
    a,b = map(int,stdin.readline().split())
    lst.append([a,b])
    q=max(q,b*c)
def cout(x):
    res=n
    for i,item in enumerate(lst):
        y,z=item[0],item[1]
        res+=(x*y//z)
    return res
l,r=0,q
while l+1<r:
    mid = (l+r)//2
    result=cout(mid)
    if result<c:l=mid
    elif result>c:r=mid
    else:break
from sys import exit
if r-l==1:
    if cout(l)!=c and cout(r)!=c:print(0);exit()
i,j=l,mid
while i+1<j:
    middle=(i+j)//2
    if cout(middle)==c:j=middle
    else:i=middle
i2,j2=mid,r
while i2+1<j2:
    middle2=(i2+j2)//2
    if cout(middle2)==c:i2=middle2
    else:j2=middle2
if i2==j:
    if cout(j)!=c:print(0);exit()
print(i2-j+1)