a = 1
b = [1, 2, 4, 3]
c = [1, 3, 4, 2]
d = [1, 4]

n = int(input())
print(1 + b[n % 4] + c[n % 4] + d[n % 2])