n=int(input())
c=0
while n:
   c+=n%2
   n//=2
print(c)