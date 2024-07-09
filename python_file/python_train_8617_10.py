N = int(input())
S = input()

seg = [0]*(2*N-1)

def update(k, x):
    k += N-1
    seg[k] = 2**x
    while k:
        k = (k-1)//2
        seg[k] = seg[2*k+1] | seg[2*k+2]
        
def query(p, q):
    p += N-1
    q += N-2
    res = 0
    while q-p > 1:
        if p&1 == 0:
            res = res | seg[p]
        if q&1 == 1:
            res = res | seg[q]
            q -= 1
        p //= 2
        q = (q-1)//2
    if p == q:
        res |= seg[q]
    else:
        res |= seg[p] | seg[q]
    return bin(res).count("1")

def f(s):
    return ord(s) - ord("a") + 1

for i in range(N):
    update(i, f(S[i]))
    
Q = int(input())
for _ in range(Q):
    a,b,c = map(str, input().split())
    if a == "1":
        update(int(b)-1, f(c))
    else:
        print(query(int(b)-1, int(c)))