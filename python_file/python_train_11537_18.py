import bisect
A,B,Q = map(int,input().split())
S = [-float('inf')]+list(int(input())for i in range(A))+[float('inf')]
T = [-float('inf')]+list(int(input())for i in range(B))+[float('inf')]
x = list(int(input())for i in range(Q))

for i in x:
    si = bisect.bisect_left(S,i)
    ti = bisect.bisect_left(T,i)
    ans = min(max(S[si],T[ti])-i,i-min(S[si-1],T[ti-1]),\
            2*S[si]-i-T[ti-1],2*T[ti]-i-S[si-1],\
             T[ti]+i-2*S[si-1],S[si]+i-2*T[ti-1])
    print(ans)