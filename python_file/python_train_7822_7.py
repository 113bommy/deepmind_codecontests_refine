from collections import deque

n = int(input())
a = deque(map(int, input().split()))

ret = ''
last = 0
i = 0
while i < n and max(a[0], a[-1] > last):
    if a[0] > last and (a[0] < a[-1] or a[-1] <= last):
        ret += 'L'
        last = a.popleft()
    elif a[-1] > last:
        ret += 'R'
        last = a.pop()
    i += 1

print(len(ret))
print(ret)