n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
for i in arr:
    if i == 2:
        print(2)
        continue
    else:
        print(i % 2)