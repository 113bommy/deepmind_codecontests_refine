n = int(input())
l = 0; r = 0
for i in range(n):
    x, y = map(int, input().split())
    if x > 0:
        r += 1
    else:
        l += 1
if l <= 1 or r <= 1:
    print('Yes')
else:
    print('No')