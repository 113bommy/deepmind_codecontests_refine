N = int(input())
A = [int(i) for i in input().split()]
AS = sorted(list(set(A)))

def f(x):
    B = [((x<=a)<<1)-1 for a in A]
    C = [N]
    [C.append(C[-1]+b) for b in B]

    r = 0
    Bit = [0] * (2*N+1)

    for i,c in enumerate(C):
        t=c-1
        while(t>0):
            r += Bit[t]
            t -= t&-t
        t=c-1
        while(t<=2*N+1):
            Bit[t] += 1
            t += t&-t
    return(r>=N*(N+1)//4)

l = 0
r = len(AS)-1
while l != r:
    if f(AS[(l+r+1)//2]):
        l = (l+r+1)//2
    else:
        r = (((l+r+1)//2)-1)
print(AS[r])
