n, a, b, c, d = map(int, input().split())

s = input()

if s.find('##',a,c) < 0 and s.find('##',b,d) < 0:
    if c<d :
        print('Yes')
    else :
        if s.find('...',b,d)>=0:
            print('Yes')
        else :
            print('No')
else :
    print('No')