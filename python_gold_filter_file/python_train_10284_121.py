K = int(input())
A, B = map(int, input().split())

if (A-1)//K!=B//K:
    print('OK')
else:
    print('NG')