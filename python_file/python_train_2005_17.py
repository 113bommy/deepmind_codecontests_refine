for i in range(int(input())):
    n = int(input())
    a = input()
    b = input()
    a = list(a)
    b = list(b)
    d = []
    e = 0
    i = 0
    while(a != b):
        if(a[i] != b[i]):
            c = a[:i+1]
            del a[:i+1]
            e += 1
            d.append(i+1)
            d.append(1)
            d.append(i+1)
            for j in range(len(c)):
                if(c[j] == '0'):
                    c[j] = '1'
                else:
                    c[j] = '0'
            c.reverse()
            if(c[0] == '0'):
                c[0] = '1'
            else:
                c[0] = '0'
            for j in range(len(c)):
                if(c[j] == '0'):
                    c[j] = '1'
                else:
                    c[j] = '0'
            c.reverse()
            a = c+a
        else:
            i += 1
    print(3*e, *d)
