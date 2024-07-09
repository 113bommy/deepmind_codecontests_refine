from bisect import bisect_left as bisect
N,Q = map(int,input().split())
event = [tuple(map(int,input().split())) for i in range(N)]
D = [int(input()) for i in range(Q)]

event.sort(key=lambda x:x[2])

ans = [-1]*Q
neg = [-1]*Q

for s,t,x in event:
    l = bisect(D,s-x)
    r = bisect(D,t-x)
    t = l
    while t < r:
        if neg[t] == -1:
            ans[t] = x
            neg[t] = r
            t += 1
        else:
            t = neg[t]

for i in range(Q):
    print(ans[i])