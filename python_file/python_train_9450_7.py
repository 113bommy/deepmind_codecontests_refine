n, k = map(int, input().split())
a = [int(i) - 1 for i in input().split()]
ans = 0
while k:
    if k & 1:
        ans = a[ans]
    c = [a[a[i]] for i in range(n)]
    a = c[:]
    k >>= 1
print(ans + 1)