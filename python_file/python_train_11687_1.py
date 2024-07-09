def printMatrix(matrix):
    s = [[str(e) for e in row] for row in matrix]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print("_________________")
    print('\n'.join(table))
    print("`````````````````")

for _ in range(int(input())):
    n,k,l = map(int,input().split())
    List = [int(x) for x in input().split()]
    Ranges = []
    for i in range(n):
        x = l - List[i]
        if(x>k):
            x = k
        Ranges.append([-x,x])
    # print(Ranges)
    start = Ranges[0][0]
    flag = 0
    for i in range(1, n):
        if(start + 1 > Ranges[i][1]):
            flag = 1
            break
        else:
            if(Ranges[i][1]!=k):
                Ranges[i][0] = max(start + 1, Ranges[i][0])
            start = Ranges[i][0]
    if(flag):
        print("No")
    else:
        print("Yes")

