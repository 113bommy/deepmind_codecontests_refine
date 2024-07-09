D = int(input())
c = list(map(int, input().split()))
s = [list(map(int, input().split())) for i in range(D)]
t = [0] * D
for i in range(D):
    t[i] = int(input())
M = int(input())   
day = [0] * M
q = [0] * M
for i in range(M):
    day[i], q[i] = map(int, input().split())
    
    
m=[0]*D

a=[[0 for i in range(26)] for j in range(D)]
for u in range(D):
    i=t[u]
    for y in range(u,D):
        a[y][i-1]=u+1
    if u==0:
        m[u]=s[u][i-1]
    else:
        m[u]=m[u-1]+s[u][i-1]
mm=[0]*D
for d  in range(D):
    for i in range(26):
        mm[d]+=c[i]*(d+1-a[d][i])
    if not d==0:
        mm[d]+=mm[d-1]
for d in range(D):
    m[d]-=mm[d]
mmm=m[D-1]
#print(mmm)
#for i in a:
 #   print(i)
for p in range(M):
    new_type=q[p]
    old_type=t[day[p]-1]
    A=0
    B=0
    C=s[day[p]-1][old_type-1]-s[day[p]-1][new_type-1]
    for d in range(D):
        A+=c[new_type-1]*(d+1-a[d][new_type-1])+c[old_type-1]*(d+1-a[d][old_type-1])
    xday=day[p]
    if xday>1:
        before_new=a[xday-2][new_type-1]
        before_old=a[xday-2][old_type-1]
        now_new=a[day[p]-1][new_type-1]
        now_old=a[day[p]-1][old_type-1]
        for d in range(day[p]-1,D):
            if a[d][new_type-1]==now_new:
                a[d][new_type-1]=xday
            if a[d][old_type-1]==now_old:
                a[d][old_type-1]=before_old
    else:
        for d in range(day[p]-1,D):
            if a[d][old_type-1]==1:
                a[d][old_type-1]=0
            if a[d][new_type-1]==0:
                a[d][new_type-1]=1
 
        #a[d][new_type-1]+=1
        #a[d][old_type-1]-=1
    
    t[day[p]-1]=new_type
    for d in range(D):
        B+=c[new_type-1]*(d+1-a[d][new_type-1])+c[old_type-1]*(d+1-a[d][old_type-1])
    #for i in a:
     #   print(i,A,B,C)
    mmm=mmm-(B-A+C)
    print(mmm)