N = int(input())
AB = [list(map(int,input().split())) for _ in [0]*N ]

mod = 1000000007

def gcd(x,y):
    if y==0:return x
    return gcd(y,x%y)

c = {}
n0 = 0
for a,b in AB:
    if a==b==0:
        n0 += 1
    elif a==0:
        c[(0,1)] = c.get((0,1),0) +1
    elif b==0:
        c[(1,0)] = c.get((1,0),0) +1
    else:
        g = gcd(a,b)
        a,b = a//g,b//g
        if a<0:
            a *= -1
            b *= -1
        c[(a,b)] = c.get((a,b),0) +1

ans = 1
done = set()
for k,n in c.items():
    if k in done: continue
    a,b = k
    if b>0:
        an,bn = b,-a
    else:
        an,bn = -b,a
    m = c.get((an,bn),0)
    ans *= (pow(2,n,mod) + pow(2,m,mod) - 1)%mod
    ans %= mod
    done.add((a,b))
    done.add((an,bn))

ans = ans -1 +n0
ans %= mod
print(ans)