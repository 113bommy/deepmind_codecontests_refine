w = int(input())
i = 0
while i<w:
    b = input().split(" ")
    c = int(b[0])
    d = int(b[1])*2
    e = int(b[2])*3
    if (c+d+e)%2==0:
        print(0)
    else:
        print(1)
    i=i+1