n = int(input())
a = list(map(int, input().split()))
a = list(set(a))
a.sort()
if len(a) >= 2:
    print(abs(a[1]))
else:
    print('NO')