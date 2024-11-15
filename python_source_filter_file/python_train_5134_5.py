def f(n):
    if n == 1: return '1\n0'
    k, j = int(n ** 0.5), 0
    if n % 2 == 0:
        if n % 4 == 0: return '1\n4' if n > 4 else '2'
        j = 2
    if n % 3 == 0:
        if j: return '1\n6' if n > 6 else '2'
        if n % 9 == 0: return '1\n9' if n > 9 else '2'
        j = 3
    for i in range(5, k, 6):
        if n % i == 0:
            if j: return '1\n' + str(i * j) 
            if n % (i * i) == 0: return '1\n' + str(i * i)
            j = i
    for i in range(7, k, 6):
        if n % i == 0:
            if j: return '1\n' + str(i * j) 
            if n % (i * i) == 0: return '1\n' + str(i * i)
            j = i
    return '2' if k * k == n else '1\n0'
print(f(int(input())))
