a=int(input())
n=a
m=1
for i in range(1,a//2+1):
    if a%i==0:
        if (i>n and a//i>n) or (i>m and a//i>m):
            n=i
            m=a//i
print(n)
print(m)
