n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

if sum(a) < sum(b):
    print("No")
else:
    print("Yes")