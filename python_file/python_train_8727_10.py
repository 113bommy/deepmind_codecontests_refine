N=int(input())

for h in range(1, 3501):
    for w in range(1, 3501):
        if 4*h*w-N*(h+w)!=0:
            n=N*h*w/(4*h*w-N*(h+w))
            if n.is_integer() and n>0:
                print(h,int(n),w)
                exit()
