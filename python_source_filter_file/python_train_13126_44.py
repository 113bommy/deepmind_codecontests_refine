import sys, math
n, *a = map(int, sys.stdin.read().strip().split())
if sum(a[n:-1]) > sum(a[:n]):
    print('No')
else:
    print('Yes')
