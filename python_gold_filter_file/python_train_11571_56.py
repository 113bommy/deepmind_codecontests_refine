s = input()
s = s.split(' ')

n = int(s[0])
v = int(s[1])

if v >= n - 1:
    print(n - 1)
else:
    r = n
    for i in range(2, n - v):
        r = r + i
    print(r)
