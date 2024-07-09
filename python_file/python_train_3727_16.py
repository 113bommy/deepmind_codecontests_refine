from heapq import heapify, heappush, heappop

def max2(x, y): return x if x >= y else y

def solve(As, Bs):
    for A, B in zip(As, Bs):
        if A > B:
            return -1

    PQ = [(-B, i) for i, (A, B) in enumerate(zip(As, Bs)) if A != B]
    heapify(PQ)
    ans = 0
    while PQ:
        B, i = heappop(PQ)
        A, B = As[i], -B
        sumNeib = Bs[i-1] + Bs[(i+1)%N]

        if B <= sumNeib or B-sumNeib < A:
            return -1
        num = (B - max2(A, sumNeib)) // sumNeib
        B -= sumNeib * num
        if B-sumNeib >= A:
            B -= sumNeib
            num += 1

        if A != B:
            heappush(PQ, (-B, i))
        Bs[i] = B
        ans += num

    return ans


N = int(input())
As = list(map(int, input().split()))
Bs = list(map(int, input().split()))

ans = solve(As, Bs)
print(ans)
