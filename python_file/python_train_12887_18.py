n = int(input())
l = list(map(int, input().split()))

l.sort()

import bisect
ans = 0
for i in range(n):
    for j in range(i+1, n):
        ans += bisect.bisect_left(l[j+1:], l[i] + l[j])

print(ans)