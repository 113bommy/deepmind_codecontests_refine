n,C,*H=map(int,open(0).read().split());
dp=[0];
P=[0];
def f(I,h):
    return dp[I]+H[I]*(H[I]-2*h)
for i in range(1,n):
    h=H[i]
    while len(P)>1 and f(P[0],h)>f(P[1],h):P.pop(0)
    dp+=[f(P[0],h)+h**2+C]
    while len(P)>1 and (H[P[-1]]-H[P[-2]])*(f(P[-1],0)-f(i,0))>(h-H[P[-1]])*(f(P[-2],0)-f(P[-1],0)):P.pop()
    P+=[i]
print(dp[-1])