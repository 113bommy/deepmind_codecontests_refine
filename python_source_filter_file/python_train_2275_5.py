n = int(input())
a = list(map(int, input().split()))
if sum(a) % 2 == 0:
    print("Yes")
else:
    print("No")