a, b = input().split()
a = int(a)
b = int(b)
q = 1
for i in range(1,min(a,b)):
    q*=i
print(q)