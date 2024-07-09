N = int(input())
S = input()
count = 0

for i in range(1000):
    pin = ("00" + str(i))[-3:]

    j = 0
    for num in S:
        if pin[j] == num:
            j += 1
        if j == 3:
            count += 1
            break

print(count)
