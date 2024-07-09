import sys
from itertools import accumulate

n, k, *aaa = map(int, sys.stdin.buffer.read().split())

for _ in range(k):
    bbb = [0] * (n + 1)
    for i in range(n):
        a = aaa[i]
        bbb[max(0, i - a)] += 1
        bbb[min(n, i + a + 1)] -= 1

    aaa = list(accumulate(bbb))
    aaa.pop()

    if all(a == n for a in aaa):
        break

print(*aaa)
