c, v0, v1, a, l = map(int, input().split())
cur = cnt = 0
while cur < c:
    cur = max(0, cur - l)
    cur += min(v1, v0 + a * cnt) - l
    cnt += 1
print(cnt)