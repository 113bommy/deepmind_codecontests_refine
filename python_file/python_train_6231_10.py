n,m=map(int,input().split())
e=[tuple(map(int,input().split())) for _ in range(m)]
d=[0]+[-float('inf')]*(n-1)
for _ in range(n-1):
    for a,b,c in e:
        d[b-1]=max(d[b-1],d[a-1]+c)
r=d[n-1]
for _ in range(n-1):
    for a,b,c in e:
        d[b-1]=max(d[b-1],d[a-1]+c)
if d[n-1]==r:
    print(r)
else:
    print('inf')