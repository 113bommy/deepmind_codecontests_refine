a,b = [int(x) for x in input().split()] 
if abs(b-a) <= 1 and a*b != 0:
    print('YES')
else:
    print('NO')