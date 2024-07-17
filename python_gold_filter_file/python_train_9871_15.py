#!/mnt/c/Users/moiki/bash/env/bin/python
N = int(input())
H = list(map(int, input().split()))
A = list(map(int, input().split()))
# ---------------------------------------------------------------------------------
from collections import deque
N0 = 2**(N).bit_length()
INF = float("inf")
INF = -(2**31-1) 

data = [INF]*(2*N0)

def update(k,x):
    k += N0 - 1
    data[k] = x
    # oldk = k
    # k += N0-1 # $B$3$N:n6H$O!D!D(B? #$B0lHV2<$NCJ$K(B
    # data[k] = k # $B$3$l@N$NCM$rF~$l$J$$$H$$$1$J$$$s$8$c$J$$$N!)(B
    # data[k] = oldk # $B$3$l@N$NCM$rF~$l$J$$$H$$$1$J$$$s$8$c$J$$$N!)(B
    while k >= 0:
        k = (k-1)//2
        data[k] = max(data[2*k+1], data[2*k+2])

# $B6h4V(B[l, r)$B$N:G>.CM(B
def query(l,r):
    L = l + N0 # $B$J$s$G(BN0$B$rB-$7$F$$$k!D(B?
    R = r + N0
    s = INF
    while L < R:
        if R & 1:
            R -= 1
            s = max(s,data[R-1])
        if L & 1:
            s = max(s, data[L-1])
            L += 1
        L >>= 1; R >>= 1
    return s
# ---------------------------------------------------------------------------------
dp = [0] * (N+1)
#dp = [ [0] * (N+1) for _ in range(2*10**5+1)]

for i in range(1,N+1):
    dp[i] = max(query(0, H[i-1]), 0) + A[i-1]
    update(H[i-1], dp[i])
print(max(dp))

