x = int(input())
y = int(input())

for i in range(0,200):
    if x**i==y:
        print("YES")
        break
    elif x**i>y:
        print("NO")
        break