from heapq import heappop, heappush
Q = int(input())
n, a, b = map(int, input().split())
mi = b
L = [-a]
R = [a]
num = 1
for i in range(Q - 1):
    q = list(map(int, input().split()))
    if len(q) == 3:
        if num % 2 != 0:
            l = -heappop(L)
            r = heappop(R)
            l1 = min(l, q[1])
            r1 = max(r, q[1])
            heappush(L, -l1)
            heappush(R, r1)
            mi += abs(l - q[1])
        else:
            if q[1] < -L[0]:
                heappush(L, -q[1])
                heappush(R, -L[0])
                mi -= q[1] + L[0]
            elif q[1] > R[0]:
                heappush(L, -R[0])
                heappush(R, q[1])
                mi += q[1] - R[0]
            else:
                heappush(L, -q[1])
                heappush(R, q[1])

        mi += q[2]
        num += 1
    else:
        print(-L[0], mi)
