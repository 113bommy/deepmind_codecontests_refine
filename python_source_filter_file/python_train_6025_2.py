def inpl(): return [int(i) for i in input().split()]
import sys
N, L = inpl()
a = inpl()
b = []
for i in range(N-1):
    b.append(a[i]+a[i+1])
bmax = max(b)
if bmax < L:
    print('Impossible')
    sys.exit()

print('Possible')
ans = b.index(bmax)

Ans = list(range(0,ans)) + list(range(1+ans,N-1))+[ans]
for i in range(N-1):
    print(Ans[i]+1)
    