N = int(input())
for i in range(1,3501):
    h = i
    for j in range(1,3501):
        n = j
        wb = (4*h*n-N*n-N*h)
        if wb > 0:
            w = (N*h*n)/wb
            if w.is_integer() is True:
                print(h,n,int(w))
                exit()
