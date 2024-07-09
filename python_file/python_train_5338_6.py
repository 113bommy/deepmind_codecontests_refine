import sys


def multiple_input(): return map(int, sys.stdin.readline().strip().split())


def list_input(): return list(map(int, sys.stdin.readline().strip().split()))


n = int(input())
a = list_input()
a.sort()
ans = [0] * n
i, j = 1, 0
count = 0
while i < n:
    ans[i] = a[j]
    if i == n - 1:
        count -= 1
    i += 2
    j += 1
    count += 1
i = 0
while i < n:
    ans[i] = a[j]
    i += 2
    j += 1
print(count)
print(*ans)