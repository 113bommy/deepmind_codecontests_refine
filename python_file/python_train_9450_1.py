n, k = [int(i) for i in input().split()]
a = [int(i)-1 for i in input().split()]
x = list(range(n))

def calc(a, b):
    c = [0] * n
    for i in range(n):
        c[i] = b[a[i]]
    return c

while k:
    if k & 1 == 1:
        x = calc(x, a)
    k //= 2
    a = calc(a, a)

print(x[0]+1)