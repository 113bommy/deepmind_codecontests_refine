n=int(input())
a=list(map(int,input().split()))
co=0
for i in range(n):
  if i%2==0 and a[i]%2==1:
    co+=1
print(co)