import math

value = int(input())
for T in range(value):
    n = int(input())
    sa = input()
    sb = input()
    count, ans = 0, []
    for i in range(1, n+1):
        i = -i
        if sa[i] != sb[i]:
            if n+1+i == 1:
                count += 1
                ans.append(1)
            else :
                count += 3
                ans.append(n+1+i)
                ans.append(1)
                ans.append(n+1+i)
    print(count,end = ' ')
    for v in ans:
        print(v, end = ' ')
    print('')
            