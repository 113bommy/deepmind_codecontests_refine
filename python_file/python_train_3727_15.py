n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0
while True:
    cnt = 0
    for i in range(n):
        m = b[(i - 1) % n] + b[(i + 1) % n]
        if 0 < m < b[i] and a[i] < b[i]:
            cnt += (b[i] - a[i]) // m
            b[i] -= (b[i] - a[i]) // m * m
    ans += cnt
    if cnt == 0:
        break
print(ans if a == b else -1)