n=int(input())
c=0

for i in range(n):
    a,b=map(int,input().split())
    if a+2<=b:
        c+=1
print(c)
