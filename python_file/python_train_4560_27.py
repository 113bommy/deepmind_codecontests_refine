N, K = map(int, input().split())
A = list(map(int, input().split()))
F = list(map(int, input().split()))
A.sort(reverse=True)
F.sort()
ok = 10**12
ng = -1
while ng+1 < ok:
    c = (ok+ng) // 2
    k = K
    for a, f in zip(A, F):
        k -= max(0, a - c//f)
    if k >= 0:
        ok = c
    else:
        ng = c
print(ok)
