import heapq

if __name__ == '__main__':
    n, M = map(int, input().split())
    ts = map(int, input().split())

    minh = []
    maxh = []
    s = 0
    for t in ts:
        while s + t > M:
            e = (-1) * heapq.heappop(maxh)
            heapq.heappush(minh, e)
            s -= e
        while minh and minh[0] + s + t <= M:
            e = heapq.heappop(minh)
            heapq.heappush(maxh, (-1)*e)
            s += e
        print(len(minh), end=" ")
        if not maxh or t <= (-1) * maxh[0]:
            heapq.heappush(maxh, (-1)*t)
            s += t
        else:
            heapq.heappush(minh, t)
