a = list(map(int, input().split()))
 
p = [list(map(int, input().split())) for i in range(a[1])]
q = [list(map(int, input().split())) for i in range(a[2])]
 
res = [[0]*a[0] for i in range(a[0])]
 
def lsadd(L,R):
    L-=1
    R-=1
    for i in range(0,L+1):  
        res[i][R] += 1
 
for l,r in p:
    lsadd(l,r)
 
for l,r in q:
    print(sum(res[l-1][:r]))