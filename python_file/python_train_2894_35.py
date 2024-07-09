from collections import defaultdict

N,Q=map(int,input().split())
l=[ tuple( map(int,input().split()) ) for i in range(N-1) ]
p=[ tuple( map(int,input().split()) ) for i in range(Q) ]
d=defaultdict(list)
for vert,childs in l:
    d[vert].append(childs)


d_2=defaultdict(int)
for i in range(1,N+1):
    d_2[i]=0

for p,x in p:
    d_2[p]+=x

for n in d_2.keys():
    for m in d[n]:
        d_2[m]+=d_2[n]

ans=d_2.values()
print(*ans)