n=int(input())
d,x=map(int,input().split())
a=0
for i in range(n):
  a=int(input())
  x+=(d-1)//a+1
print(x)