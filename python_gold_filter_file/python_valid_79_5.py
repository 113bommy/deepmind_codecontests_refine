for i in range(int(input())):
    k=int(input())
    a=list(map(int,input()))
    i=0
    e=10*[0]
    y=1
    f=[1,4,6,8,9]
    for j in a:
        if(j in f):
            print(1)
            print(j)
            y=0
            break
        e[j]=e[j]+1
    if(y==1):
        for j in range(1,len(e)):
            if(e[j]>=2):
                print(2)
                print(j+10*j)
                y=0
                break
    if(y==1):
        if a[1:].count(2):
            print(2)
            print(a[0]*10+2)
        elif a[1:].count(5):
            print(2)
            print(a[0]*10+5)
        elif e[2] > 0 and e[7] > 0:
            print('2\n27')
        elif (e[7]>0 and e[5] > 0):
            print('2\n57')
        else:
            print(-1)