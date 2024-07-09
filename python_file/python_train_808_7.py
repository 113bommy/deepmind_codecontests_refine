N = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(60 + 1):
    cnt = 0
    for a in A:
        if a >> i & 1:
            cnt += 1
    ans = (ans + 2 ** i * cnt * (N - cnt)) % (10 ** 9 + 7)
print(ans)