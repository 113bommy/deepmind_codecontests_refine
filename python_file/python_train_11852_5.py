import heapq


def small_multiple(k):
    # kの倍数で各桁の総数が最も小さくなるような、各桁の総数
    dist = [float("inf")] * k
    q = []
    # kで割った余りが1になるような最小の数は1
    heapq.heappush(q, (1, 1))

    while q:
        n, c = heapq.heappop(q)
        if dist[n] <= c:
            continue
        dist[n] = c

        if dist[(n + 1) % k] > c + 1:
            heapq.heappush(q, ((n + 1) % k, c + 1))
        if dist[(n * 10) % k] > c:
            heapq.heappush(q, ((n * 10) % k, c))

    print(dist[0])


def main():
    k = int(input())
    small_multiple(k)


if __name__ == "__main__":
    main()
