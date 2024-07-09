mod = 998244353
from bisect import bisect_left as bisect
from operator import itemgetter
N = int(input())
XD = [list(map(int,input().split())) for _ in range(N)]
XD.sort(key=itemgetter(0))
X = [XD[i][0] for i in range(N)]
D = [XD[i][1] for i in range(N)]

N0 = 2**(N-1).bit_length()
INF = 2**31-1
data = [INF]*(4*N0)

def update(k, x):
    k += N0-1
    data[k] = x
    while k >= 0:
        k = (k - 1) // 2
        data[k] = min(data[2*k+1], data[2*k+2])

def query(l, r):
    L = l + N0; R = r + N0
    s = INF
    while L < R:
        if R & 1:
            R -= 1
            s = min(s, data[R-1])

        if L & 1:
            s = min(s, data[L-1])
            L += 1
        L >>= 1; R >>= 1
    return s

for i in range(N-1,-1,-1):
    x,d = XD[i]
    j = bisect(X,x+d)
    update(i,-i)
    update(i,query(i,j))

dp = [1]*(N+1)

for i in range(N-1,-1,-1):
    j = -query(i,i+1)
    dp[i] = dp[i+1] + dp[j+1]
    dp[i] %= mod

print(dp[0])
