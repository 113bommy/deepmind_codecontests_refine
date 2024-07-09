n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
x, y = 0, 0
ans = 1
if len(set(a)) < n or len(set(b)) < m:
    exit(print(0))
for i in range(n * m, 0, -1):
    if i in a and i in b:
        x += 1
        y += 1
    elif i in a:
        ans *= x
        y += 1
    elif i in b:
        ans *= y
        x += 1
    else:
        ans *= x * y - n * m + i
    ans %= 10 ** 9 + 7
print(ans)