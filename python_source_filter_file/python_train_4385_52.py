x, y, z, t1, t2, t3 = map(int, input().split())
print('YES' if (abs(z-x) + abs(x-y)) * t2 + 2 * t3 <= abs(x-y) * t1 else 'NO')
