n,a,b,c,d=tuple(map(int,input().split()))
ans=0
sum=0
def ch(c):
    return (n>=c and c>0)

for i in range(n):
    sum=i+a+b
    x2=sum-a-d
    x3=sum-c-d
    x4=sum-b-c
    if ch(i) and ch(x2) and ch(x3) and ch(x4):
        ans+=1

print(ans*n)