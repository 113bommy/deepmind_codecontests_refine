n, k = map(int, input().split())
a = [int(x) - 1 for x in input().split()]
now = 0
b = [0] * n
while k!= 0:
    if k & 1:
        now = a[now]
    k >>= 1
    for i in range(n):
        b[i] = a[a[i]]
    a = b[:]
print(now+1)