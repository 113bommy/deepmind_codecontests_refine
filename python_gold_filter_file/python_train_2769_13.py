
n,m=map(int,input().split())
s=1
m=min(m,n)
while(m>0):
    s=s*m
    m=m-1
print(s)
