n, k = map(int, input().split())
a = list(map(int, input().split()))


for i in range(k):
    b = [0] * (n+1)
    for j in range(n):
        l = max(0, j-a[j])
        r = min(n, j+a[j]+1)
        b[l] += 1
        b[r] -= 1
    for j in range(n):
        b[j+1] += b[j]
    b.pop()
    if a == b:
        break
    a = b
print(' '.join(map(str, a)))