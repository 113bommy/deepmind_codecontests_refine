P=10**9+7
def egcd(a, b):
    (x, lastx) = (0, 1)
    (y, lasty) = (1, 0)
    while b != 0:
        q = a // b
        (a, b) = (b, a % b)
        (x, lastx) = (lastx - q * x, x)
        (y, lasty) = (lasty - q * y, y)
    return (lastx, lasty, a)
def inv(x):
    return egcd(x,P)[0]
N=int(input())
Fact=[0 for i in range(N+1)]
Finv=[0 for i in range(N+1)]
Fact[0]=1
Finv[0]=1
for i in range(N):
    Fact[i+1]=((i+1)*Fact[i])%P
    Finv[i+1]=(Finv[i]*inv(i+1))%P
SGN=[0 for i in range(N)]
ans=0
for k in range(N):
    if 2*k-N>=0:
        SGN[k]=(((Fact[k-1]*Fact[k])%P)*Finv[2*k-N])%P
        ans=(ans+k*(SGN[k]-SGN[k-1]))%P
print(ans)
