n = int(input())
m = int(input())
if n > 26:
    print(m)
else:
    print(m % (2 ** n))
