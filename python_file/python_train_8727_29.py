N = int(input())
for h in range(3501):
    for n in range(3501):
        if 4*h*n - N*n - N*h == 0:
            continue
        w = N*h*n / (4*h*n - N*n - N*h)
        if w > 0 and int(w) == w:
            print(h, n, int(w))
            exit()
