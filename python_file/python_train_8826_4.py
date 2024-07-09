from collections import Counter
N = int(input())
A = list(map(int, input().split()))
C = Counter(A)
C = list(C.values())
C.sort()
n = len(C)
m = max(C)
S = [0]*(m+1)
b = 0
for i in range(n):
    c = C[i]
    if b<c:
        for j in range(b+1, c+1):
            S[j] = S[j-1]+(n-i)
        b = c
for i in range(1, N+1):
    ok = 0
    ng = N+1
    while ng-ok>1:
        mid = (ok+ng)//2
        if S[min(m, mid)]>=mid*i:#midが条件を満たすか
            ok = mid
        else:
            ng = mid
    print(ok)
