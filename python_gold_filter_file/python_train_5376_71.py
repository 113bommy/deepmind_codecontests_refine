n = int(input())
m = int(input())
if n < 27:
    print(m % (1 << n))
else:
    print(m)