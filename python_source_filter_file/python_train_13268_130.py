n = int(input())
count = 0
for i in range(n):
    p, q = map(int, input().split())
    if p < q:
        count += 1

print(count)