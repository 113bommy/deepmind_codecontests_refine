n = int(input())
c = list(map(int, input().split()))
while True:
    f = False
    for i in range(1, n):
        if c[i] < c[i-1]:
            f = True
            c[i], c[i-1] = c[i-1], c[i]
            print(i+1, i+2)
    if not f:
        break
