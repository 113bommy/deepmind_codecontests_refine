N = int(input())

def crt(rs,ms):
    def _inv_gcd(a,b):
        if a==0: return (b,0)
        s,t,m0,m1 = b,a,0,1
        while t:
            u = s // t
            s -= t * u
            m0 -= m1 * u
            tmp = s
            s = t
            t = tmp
            tmp = m0
            m0 = m1
            m1 = tmp
        if m0 < 0: m0 += b//s
        return (s, m0)
    assert len(rs) == len(ms)
    n = len(rs)
    r0,m0 = 0,1
    for i in range(n):
        assert 1 <= ms[i]
        r1,m1 = rs[i] % ms[i], ms[i]
        if m0 < m1:
            r0,r1,m0,m1 = r1,r0,m1,m0
        if m0 % m1 == 0:
            if r0 % m1 != r1: return (0,0)
            continue
        g,im = _inv_gcd(m0,m1)
        u1 = m1 // g
        if (r1-r0) % g: return (0,0)
        x = (r1-r0) // g % u1 * im % u1
        r0 += x * m0
        m0 *= u1
        if r0 < 0: r0 += m0
    return (r0,m0)

divs = set()
m = 1
NN = 2*N
while m*m <= NN:
    if NN%m == 0:
        divs.add(m)
        divs.add(NN//m)
    m += 1

ans = NN-1
for x in divs:
    y = NN//x
    if y==1: continue
    r,m = crt([0,-1], [x,y])
    if r==m==0: continue
    ans = min(ans, r)

print(ans)