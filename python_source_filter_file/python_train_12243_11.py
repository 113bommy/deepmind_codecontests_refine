a=[0, 70, 2*60+20, 3*60+30, 4*60+50, 5*60+50, 10*60+1, 11*60+11, 12*60+21,13*60+31,
   14*60+41, 15*60+51,20*60+2,21*60+12,22*60+22,23*60+32,24*60]
h,m=map(int, input().split(':'))
t=h*60+m
for x in a:
    if x-t>=0:
        print(x-t)
        break
