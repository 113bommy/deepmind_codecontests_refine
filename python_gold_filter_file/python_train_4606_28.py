a = bin(int(input()))[2:]
a = a.zfill(6)
b = "".join([a[0], a[5], a[3], a[2], a[4], a[1]])
print(int(b, 2))