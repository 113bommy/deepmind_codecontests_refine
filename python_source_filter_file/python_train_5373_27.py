s = input()
k = int(input())

if k > len(s):
    print('impossible')
else:
    dis = len(set(list(s)))
    print(k-dis)