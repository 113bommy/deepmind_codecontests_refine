n, k = map(int, input().split())
next = list(map(int, input().split()))
next = list(map(lambda x: x - 1, next))
c = list(map(int, input().split()))

ans = -(10 ** 17)

for i in range(n):
    now = i
    cycle_sum = 0
    cycle_len = 0

    while True:
        cycle_sum += c[now]
        cycle_len += 1
        now = next[now]
        if now == i:
            break

    sum = 0
    cnt = 0

    while True:
        sum += c[now]
        cnt += 1

        if cnt > k:
            break

        laps = (k - cnt) // cycle_len
        score = sum + max(0, cycle_sum) * laps
        ans = max(ans, score)

        now = next[now]
        if now == i:
            break

print(ans)