n, a, b = [int(i) for i in input().split(" ")]

def p2l(x):
    l = []
    for i in range(0, n):
        l = [x % 2] + l
        x = x // 2
    return l

def l2p(x):
    return sum([x[i] * 2**(len(x) - i - 1) for i in range(0, len(x))])

al = p2l(a)
bl = p2l(b)

def gray(a, b):
    if len(a) == 1:
        return [a, b]
    
    for i in range(0, len(a)):
        if a[i] != b[i]:
            break
    ah = a[i]
    bh = b[i]
    del a[i]
    del b[i]
    
    c = [1 - a[0]] + a[1:]
    g1 = gray(a[:], c[:])
    g2 = gray(c[:], b[:])
    g1 = [h[0:i] + [ah] + h[i:] for h in g1]
    g2 = [h[0:i] + [bh] + h[i:] for h in g2]
    return g1 + g2

if sum(al) % 2 != sum(bl) % 2:
    print("YES")
    g = gray(al, bl)
    p = [l2p(gi) for gi in g]
    print(' '.join(map(str, p)))
else:
    print("NO")