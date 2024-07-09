def get_sum(a, n):
    count = 0

    for i in range(1, n-1):
        for j in range(1, n-1):
            count += a[i][j]

    count += a[0][0] + a[0][-1] + a[0][n//2]
    count += a[-1][0] + a[-1][-1] + a[-1][n//2]
    count += a[n//2][0] + a[n//2][-1]
    return count


n = int(input())
table = [[int(i) for i in input().split()] for j in range(n)]
if n == 1:
    print(table[0][0])
else:
    print(get_sum(table, n))

