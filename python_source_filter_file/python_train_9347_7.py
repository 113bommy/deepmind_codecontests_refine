import sys
n = int(input())
a = list(map(int, input().split()))
tmp=sys.maxsize
s = sum(a)
for i in range(n):
    t += a[i]
    tmp = min(tmp,abs(s-t*2))
print(tmp)