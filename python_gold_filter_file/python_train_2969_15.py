n, a, b = input().split()
n = int(n)
if b[0] is 'w':
    print((52,53)[n>=5 and n <= 6])
else:
    if n is 31:
        print(7)
    else:
        print((11,12)[n<30])