n, m = map(int, input().split())

card = [[] for _ in range(n)]

for _ in range(m):
    x, y, _ = map(int, input().split())
    card[x-1].append(y-1)
    card[y-1].append(x-1)

checked = [False] * n

count = 0
from collections import deque
for i in range(n):
    if checked[i]:
        continue
    count += 1
    q = deque([i])
    while q:
        j = q.popleft()
        checked[j] = True
        for k in card[j]:
            if not checked[k]:
                q.append(k)
print (count) 

