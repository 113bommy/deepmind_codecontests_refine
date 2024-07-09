from operator import itemgetter
import sys


def add(arr, i, size):
    while i < size:
        arr[i] += 1
        i += i & -i


def sub(arr, i, size):
    while i < size:
        arr[i] -= 1
        i += i & -i


def bit_sum(arr, a, b):
    s = 0
    i = b
    while i > 0:
        s += arr[i]
        i -= i & -i
    i = a - 1
    while i > 0:
        s -= arr[i]
        i -= i & -i
    return s


def read():
    return sys.stdin.readline().rstrip()


def main():
    n, q = map(int, read().split())
    c = [int(i) - 1 for i in read().split()]
    queries = [(0, 0, 0) for _ in range(q)]
    for i in range(q):
        l, r = map(int, read().split())
        queries[i] = (i, l, r)
    queries = iter(sorted(queries, key=itemgetter(2)))
    last = [0] * n
    bit = [0] * (n + 1)
    ans = [-1] * q
    k, l, r = next(queries)
    for i in range(n):
        ci = c[i]
        li = last[ci]
        if li > 0:
            sub(bit, li, n + 1)
        last[ci] = i + 1
        add(bit, i + 1, n + 1)
        while i + 1 == r:
            ans[k] = bit_sum(bit, l, r)
            try:
                k, l, r = next(queries)
            except StopIteration:
                print(*ans, sep="\n")
                return


if __name__ == '__main__':
    main()
