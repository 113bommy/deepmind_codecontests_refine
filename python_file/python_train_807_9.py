N = int(input())
A = list(map(int, input().split()))

B = [(A[i], i) for i in range(N)]
B.sort(key = lambda x: x[0], reverse = True)

DP = [[0] * (N + 1) for _ in range(N + 1)]

for i in range(N):
    a = B[i][0]
    tmp = B[i][1]
    for x in range(i + 1):
        DP[x + 1][i - x] = max(DP[x + 1][i - x], DP[x][i - x] + a * abs(tmp - x))
        DP[x][i - x + 1] = max(DP[x][i - x + 1], DP[x][i - x] + a * abs((N - tmp - 1) - (i - x)))

ans = 0
for i in range(N + 1):
    ans = max(ans, DP[i][N - i])

print (ans)

# for tmp in DP:
#     print (tmp)