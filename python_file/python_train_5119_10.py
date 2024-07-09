n, m = map(int, input().split())
qw = [int(i) for i in input().split()]
lk = []

lk.append(0)
b = 0

lki = []
def insert(arr, elem):
    if len(arr) >= 110:
        if arr[-1] >= elem:
            return
        arr[-1] = elem
    else:
        arr.append(elem)
    for i in range(len(arr) - 1, 0, -1):
        if arr[i] > arr[i-1]:
            arr[i], arr[i-1] = arr[i-1], arr[i]

for i in range(1, n):
    b += qw[i-1]
    insert(lki, qw[i-1])

    if m >= b + qw[i]:
        lk.append(0)
        continue
    # m < b + qw[i]
    z = 0
    rest = b + qw[i] - m
    for u in range(len(lki)):
        z += lki[u]
        if rest <= z:
            lk.append(u+1)
            break

print(*lk)