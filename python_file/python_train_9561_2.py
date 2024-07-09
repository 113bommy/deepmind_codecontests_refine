N,K= map(int,input().split())
x=[0]*N
y=[0]*N
z=[0]*N
for i in range(N):
    x[i],y[i] = map(int,input().split())
    z[i] = (x[i],y[i])
    
ans=float("inf")
for s in x:
    for t in x:
        for u in y:
            for v in y:
                cnt=0
                for zz in z:
                    if s<= zz[0]<=t and u<=zz[1]<=v:
                        cnt +=1
                if cnt >=K:
                    tmp = (t-s)*(v-u)
                    ans = min(ans,tmp)
print(ans)