n = int(input())
a = sorted(list(map(int, input().split())))
for i in range(1, 5000):
    if i not in a:
        print(i)
        exit(0)
