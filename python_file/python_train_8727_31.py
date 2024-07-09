N = int(input())
for n in range(1,3501):
    for w in range(1,3501):
        if 4*n*w-N*(n+w) != 0:
            h = (N*n*w)/(4*n*w-N*(n+w))

            if h > 0 and h.is_integer():
                print(int(h), n, w)
                exit()

