n = int(input())
a = [int(i) for i in input().split()]

b = [0]
for i in a:
    b.append(b[-1] + i)


def get(i, j):
    i, j = min(i, j), max(i, j)
    return b[j]-b[i]


j = 0
k = 0
ans = 10**18
for i in range(n):
    while j < n and abs(get(0, j) - get(j, i)) > abs(get(0, j + 1) - get(j + 1, i)):
        j += 1
    while k < n and abs(get(i, k) - get(k, n)) > abs(get(i, k + 1) - get(k + 1, n)):
        k += 1
    an = [get(0, j), get(j, i), get(i, k), get(k, n)]
    ans = min(ans,max(an)-min(an))
print(ans)