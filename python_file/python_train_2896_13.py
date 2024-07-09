n,k=map(int,input().split())
a=list(map(int,input().split()))
s=set()
for i in range(n):
     su=0
     for j in range(i,n):
          su+=a[j]
          s.add(su)
s=list(s)
x=0
for i in range(40):
     x_=x+2**(39-i)
     cnt=0
     for a in s:
          if x_&a==x_:
               cnt+=1
     if cnt>=k:
          x=x_
print(x)