n = int(input())
x = list(map(int, input().split()))
a = 200001 * [10 ** 6]
for i in range(n):
    a[x[i]] = i + 1
print(a.index(min(a)))
