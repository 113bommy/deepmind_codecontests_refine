for n in range(int(input())):
        c = int(input())
        g = 0
        ab = ''
        ba = ''
        a = list(input())
        b = list(input())
        if c == 2:
            a = set(a)
            b = set(b)
            if len(a ^ b) == 2:
                print('Yes')
                continue
            else:
                print('No')
                continue
        for i in range(c):
            if a[i] != b[i]:
                g += 1
                ab += a[i]
                ba += b[i]
        if g != 0 and g != 2:
            print('No')
        else:
            if g == 2:
                if ab[0] + ba[1] == ab[1] + ba[0]:
                    print('Yes')
                else:
                    print('No')
            else:
                print('Yes')
    