n = int(input())

for h in range(1,3501):
    for w in range(1,3501):
        if 4 * h * w - n * w - n * h != 0:
            N = (n * h * w) / (4 * h * w - n * w - n * h)
            if N.is_integer() and N > 0:
                print(h,w,int(N))
                exit()
