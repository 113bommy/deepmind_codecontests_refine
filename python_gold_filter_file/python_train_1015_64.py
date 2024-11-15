_N, k = map(int, input().split())
a = [int(input()) for _i in range(_N)]

n = 300002

def init_max(init_max_val):
    #set_val
    for i in range(n):
        seg_max[i+num_max-1]=init_max_val[i]    
    #built
    for i in range(num_max-2,-1,-1) :
        seg_max[i]=max(seg_max[2*i+1],seg_max[2*i+2]) 
    
def update_max(k,x):
    k += num_max-1
    seg_max[k] = x
    while k:
        k = (k-1)//2
        seg_max[k] = max(seg_max[k*2+1],seg_max[k*2+2])
    
def query_max(p,q):
    if q<=p:
        return ide_ele_max
    p += num_max-1
    q += num_max-2
    res=ide_ele_max
    while q-p>1:
        if p&1 == 0:
            res = max(res,seg_max[p])
        if q&1 == 1:
            res = max(res,seg_max[q])
            q -= 1
        p = p//2
        q = (q-1)//2
    if p == q:
        res = max(res,seg_max[p])
    else:
        res = max(max(res,seg_max[p]),seg_max[q])
    return res

#####単位元######
ide_ele_max = -1

#num_max:n以上の最小の2のべき乗
num_max =2**(n-1).bit_length()
seg_max=[ide_ele_max]*2*num_max

A = [0]*300002
init_max(A)

for i in range(_N):
    update_max(a[i], query_max(max(0, a[i]-k), min(300001, a[i]+k+1))+1)

print(query_max(0,300001))