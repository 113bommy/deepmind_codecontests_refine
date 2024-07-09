N,Q=map(int,input().split())
l=[[1,0,0]]
for i in range(1,N):
    a,b=map(int,input().split())
    l.append([b,a,0])
l.sort()
for i in range(Q):
    p,x=map(int,input().split())
    l[p-1][2]+=x
t=[l[0][2]]
for i in range(1,N):
    t.append(t[l[i][1]-1]+l[i][2])
print(*t)