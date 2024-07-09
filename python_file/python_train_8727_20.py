N = int(input())
for h in range(1,3501):
    for n in range(1,3501):
        try:
            tmp = n*h*N / ( 4*h*n - N*n - N* h)
        except:
            continue
        if tmp == tmp//1 and tmp > 0:
            print(h,n,int(tmp))
            exit()