N, K = map(int, input().split())
A = list(map(int, input().split()))
F = list(map(int, input().split()))

A.sort()
F.sort(reverse=True)

def isOk(T):
    ret = 0
    for a, f in zip(A, F):
        ret += max(0, a - T // f)
    return ret <= K

ok = max(a * f for a, f in zip(A, F))
ng = -1
while ok - ng > 1:
    mid = (ok + ng) // 2
    if isOk(mid):
        ok = mid
    else:
        ng = mid

print(ok)
