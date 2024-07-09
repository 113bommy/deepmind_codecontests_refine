n = int(input())
a = input()
a2 = [int(a[i]) for i in range(n)]
n2 = bin(n)
b = [0] * n
c = [1] * (2 ** (len(n2) - 3))
for i in range(len(c)):
    b[i] += c[i]
temp = len(n2) - 4
count = len(c)
while temp>= 0:
    if n2[-1-temp] == "1":
        c = [b[i] for i in range(count)]
        for i in range(count):
            b[i + 2 ** temp] += c[i]
        count += 2 ** temp
    temp -= 1
e = [b[i] % 2 for i in range(len(b))]
d = 0
for i in range(n):
    if e[i] % 2 == 1:
        d += a2[i]
if d % 2 == 1:
    print(1)
else:
    a3 = [abs(a2[i] - a2[i + 1]) for i in range(n - 1)]
    if 1 in a3:
        print(0)
    else:
        n3 = bin(n - 1)
        b = [0] * (n - 1)
        c = [1] * (2 ** (len(n3) - 3))
        for i in range(len(c)):
            b[i] += c[i]
        temp = len(n3) - 4
        count = len(c)
        while temp>= 0:
            if n3[-1-temp] == "1":
                c = [b[i] for i in range(count)]
                for i in range(count):
                    b[i + 2 ** temp] += c[i]
                count += 2 ** temp
            temp -= 1
        e = [b[i] % 2 for i in range(len(b))]
        d = 0
        for i in range(n - 1):
            if e[i] % 2 == 1:
                d += a3[i]
        if d % 4 == 0:
            print(0)
        else:
            print(2)