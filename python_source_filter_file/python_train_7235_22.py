n = int(input())
l = list(map(int, input().split()))
count = l[0]

for i in range(n - 1):
    c = abs(l[i] - l[i + 1])
    count += c

print(count)
