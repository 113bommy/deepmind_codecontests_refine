t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    int_sum = [[0 for _ in range(27)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, 27):
            if a[i-1] == j:
                int_sum[i][j] = int_sum[i-1][j] + 1
            else:
                int_sum[i][j] = int_sum[i-1][j]

    ans = 0
    for i in range(n+1):
        for j in range(i, n+1):
            max_a, max_b = 0, 0
            for k in range(1, 27):
                max_a = max(max_a, min(int_sum[n][k] - int_sum[j][k],
                                       int_sum[i][k]))
                max_b = max(max_b, int_sum[j][k] - int_sum[i][k])
            ans = max(ans, max_a * 2 + max_b)

    print(ans)