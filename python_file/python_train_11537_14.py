import bisect

a,b,q = map(int,input().split())
s = [-10**11] + [int(input()) for i in range(a)] + [10**11]
t = [-10**11] + [int(input()) for i in range(b)] + [10**11]



for i in range(q):
    x = int(input())
    xs = bisect.bisect_right(s,x)
    xt = bisect.bisect_right(t,x)
    ss = [x-s[xs-1],s[xs]-x]
    tt = [x-t[xt-1],t[xt]-x]
    print(min(max(ss[0],tt[0]), max(ss[1],tt[1]), ss[0]*2+tt[1], ss[1]*2+tt[0], tt[0]*2+ss[1], tt[1]*2+ss[0]))
