N, C, K = map(int, input().split())
T = sorted([int(input()) for _ in range(N)])
s, c = 0, 0
ans = 0
for t in T:
    if t <= s + K and c:
        c -= 1
    else:
        s = t
        c = C - 1
        ans += 1
print(ans)
