x = int(input())

for i in range(100):
    for j in range(-100, 0):
        if i ** 5 - j ** 5 == x:
            print(i, j)
            exit()