import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
a = list(map(int, input().split()))

from collections import Counter, defaultdict
c = Counter(a)
n1, n2, n3 = c[1], c[2], c[3]
n0 = c[0]
def glist(*l, fill=None):
    if len(l)==1:
        return [fill]*l[0]
    ll = l[1:]
    return [glist(*ll) for _ in range(l[0])]

count = 0
S = sum(a)
sub = glist(n1+n2+n3+1,n2+n3+1,n3+1)
sub[0][0][0] = 0
#     for i1 in range(min(n+1, s+1)):
#         for i2 in range(min(n+1, (s-i1)//2+1)):
for i3 in range(n3+1):
    for i2 in range(n2+n3+1-i3):
        for i1 in range(n1+n2+n3 - (i2+i3) + 1):
            if i1==i2==i3==0 or i1+i2+i3>n:
                continue
#             print(i1,i2,i3)
            ans = n
            p = 0
            if i1>0:
                ans += i1 * sub[i1-1][i2][i3]
                p += i1
            if i2>0:
                ans += i2 * sub[i1+1][i2-1][i3]
                p += i2
            if i3>0:
                ans += i3 * sub[i1][i2+1][i3-1]
                p += i3
            ans = ans/p
            sub[i1][i2][i3] = ans
print(sub[n1][n2][n3])