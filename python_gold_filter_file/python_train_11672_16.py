n, m, k, L = map(int, input().split())
L += k
ans = 0
if L % m > 0:
    ans = (L - (L % m)) // m + 1
else:
    ans = L // m
if L > n or m * ans > n or m > n:
    print(-1)
    exit()
else:
    print(ans)