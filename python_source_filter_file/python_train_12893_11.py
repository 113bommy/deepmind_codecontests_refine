n=int(input())
l=sorted(list(map(int,input().split())))
count=0
sum=n
now=l[0]
for i in range(1,n):
  if now*2<l[i]:
    sum-=count
    now=now+l[i]
    count=0
  else:
    count+=1
    now+=l[i]
print(sum)
