count = int(input())
n = []

for i in range(count):
    n.append(int(input()))

for i in n:
    if(i % 4 == 0):
        print("YES")
    else:
        print("NO")
