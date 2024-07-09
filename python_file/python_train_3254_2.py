for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    s = []
    x = -1
    size = 0
    for i in range(2*n):
        if l[i]>x:
            s.append(size)
            size = 1
            x = l[i]
        else:
            size +=1
    s.append(size)
    s.sort()
    s.reverse()
    a, b = 0, 0
    for i in s:
        if a+i<=n:
            a+=i
        else: b+=i
    print('YES' if a==n else 'NO')