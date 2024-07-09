from itertools import product
H,W,K=map(int, input().split())
pr=10**9+7
b=[0]*W
b[0]=1
z=[0]*W
rl=tuple(product([0,1], repeat=(W-1)))
l=[]
for i in rl:
    for j in range(W-2):
        if i[j] and i[j+1]:
            break
    else:
        l.append([0]+list(i)+[0])
for i in range(H):
    a=z.copy()
    for j in l:
        for k in range(W):
            if j[k]:
                a[k]=(b[k-1]+a[k])%pr
            elif j[k+1]:
                a[k]=(b[k+1]+a[k])%pr
            else:
                a[k]=(b[k]+a[k])%pr
    b=a
print(b[K-1])