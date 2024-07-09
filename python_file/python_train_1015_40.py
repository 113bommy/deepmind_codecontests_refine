N, K, *A = map(int, open(0).read().split())

A = [a + 1 for a in A]
M = max(A)

N0 = 2 ** (M - 1).bit_length()
data = [0] * (2 * N0)

def update(k, x):
    k += N0 - 1
    data[k] = x
    while k >= 0:
        k = (k - 1) // 2
        data[k] = max(data[2 * k + 1], data[2 * k + 2])

def query(l, r):
    L = l + N0; R = r + N0
    s = 0
    while L < R:
        if R & 1:
            R -= 1
            s = max(s, data[R-1])

        if L & 1:
            s = max(s, data[L-1])
            L += 1
        L >>= 1; R >>= 1
    return s

for a in A:
    x = query(max(1, a - K), min(a + K + 1, M + 1))
    update(a, x + 1)

print(query(1, M))