N=int(input())
tmp = 0
while N>0:
    for i in range(1,N+1):
        if N <= i*(i+1)//2:
            print(i)
            N -=i
            break