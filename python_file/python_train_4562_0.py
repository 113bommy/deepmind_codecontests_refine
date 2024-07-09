import sys
input = sys.stdin.readline

N, Q = map(int, input().split())
A = list(map(int, input().split()))
Query = [int(input()) for _ in range(Q)]
INF = 10**14

E = [0]
O = [0]
e = 0
o = 0
for i, a in enumerate(A):
    if i % 2 == 0:
        e += a
    else:
        o += a
    E.append(e)
    O.append(o)

S = [0]
s = 0
for a in reversed(A):
    s += a
    S.append(s)

for X in Query:
    ind = N
    if X > A[-1]:
        l = 0
    else:
        l = 0
        r = N+1
        while r-l > 1:
            m = (r+l)//2
            in_left = A[-m]
            in_right = A[-m+m//2-1]
            out_left = A[-m-1] if m < N else -INF
            out_right = A[-m+m//2] if m > 0 else INF
            if X <= out_left:
                l = m
            elif out_right <= X:
                r = m
            else:
                if abs(X-out_left) <= abs(in_right-X):
                    l = m
                elif abs(X-in_left) > abs(out_right - X):
                    r = m
                else:
                    l = m
                    break
    
    ans = S[l-l//2]
    if l%2 != (N-l)%2:
        ans += E[N-l]
    else:
        ans += O[N-l]
    
    print(ans)

