from itertools import accumulate as ac
n=int(input())
a=list(ac(list(map(int,input().split()))))
d=float("INF")
for i in range(n):
    d=min(d,abs(a[-1]-2*a[i]))
print(d)