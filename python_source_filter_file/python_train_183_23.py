n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))

m=0
for i in range(n):
  if a[i+1]==a[i]+1:
    m=m+c[i]

print(sum(b)+m)