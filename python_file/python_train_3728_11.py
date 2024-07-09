x, y, z, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = sorted(list(map(int, input().split())))[::-1]

a1 = sorted(a[i] + b[j] for i in range(x) for j in range(y))[::-1]
a2 = sorted(a1[i] + c[j] for i in range(min(len(a1), k))
            for j in range(z))[::-1]
for i in range(k):
    print(a2[i])
