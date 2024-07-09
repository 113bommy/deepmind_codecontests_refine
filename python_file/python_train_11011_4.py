n, k, *a = map(int, open(0).read().split())

for _ in range(k):
    b = [0] * -~n
    for i in range(len(a)):
        b[max(0, i - a[i])] += 1
        b[min(n, i + a[i] + 1)] -= 1
    for i in range(n):
        b[i + 1] += b[i]

    if all(x == n for x in b[:n]):
        print(' '.join(map(str, b[:n])))
        exit()
    a = b
print(' '.join(map(str, a[:n])))
