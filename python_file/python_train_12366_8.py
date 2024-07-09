import sys
from itertools import accumulate

readline = sys.stdin.readline
INF = 10 ** 9
h, w, k = map(int, readline().split())
s = [readline() for _ in range(h)]

ans = INF
for bit in range(2**h-1):
    cut = bin(bit).count('1')
    group = 0
    peace = [[0] * (bin(bit).count('1') + 1) for _ in range(w)]

    for i in range(w):
        group = 0
        for j in range(h):
            if s[j][i] == '1':
                peace[i][group] += 1
            if bit >> j & 1:
                group += 1

    if any(max(col) > k for col in peace):
        continue
    current = [0] * (bin(bit).count('1') + 1)
    for i in range(w):
        current = list(map(sum, zip(current, peace[i])))
        if max(current) > k:
            cut += 1
            current = peace[i]
    if ans > cut:
        ans = cut

print(ans)
