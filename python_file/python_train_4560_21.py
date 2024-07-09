import math
N, K = map(int, input().split())
A = sorted([int(i) for i in input().split()], reverse=True)
F = sorted([int(i) for i in input().split()])
OK = 10**12
NG = -1

while OK-NG > 1:
    mid = (OK+NG)//2
    cnt = 0
    for a, f in zip(A, F):
        if a*f > mid:
            cnt += math.ceil((a*f-mid)/f)
    if cnt <= K:
        OK = mid
    else:
        NG = mid
print(OK)
