n=int(input())
a=2
b=1
for i in range(n-1):
  a,b=b,(a+b)
print(a)