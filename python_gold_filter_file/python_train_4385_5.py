x, y, z, t1, t2, t3 = map(int, input().split())
a = abs(x - y) * t1
b = abs(x - z) * t2 + t3 + abs(x - y) * t2 + 2 * t3

if b <= a:
    print('YES')
else:
    print('NO')
