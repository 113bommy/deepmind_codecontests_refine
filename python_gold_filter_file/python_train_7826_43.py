q = int(input())
for _ in range(q):
    x, y = map(int, input().split())
    if x - y == 1:
        print("NO")
    else:
        print("YES")