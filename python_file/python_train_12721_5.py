import math
import copy
def f(base, inputNum): 
    index = 0
    res = []
    while (inputNum > 0): 
        res.append((inputNum % base))
        inputNum = int(inputNum / base)
    return res

t = int(input())
j = -1
for _ in range(t):
    n = int(input())
    res = f(3, n)
    co = copy.deepcopy(res)
    c = 0
    j = -1
    for i in range(len(res)):
        if (res[i] + c) >= 2:
            c = 1
            j = i
        elif res[i] == 0 and c == 1:
            res[i] = 1
            c = 0
    #print(res)
    if c == 1:
        res.append(1)
        j = len(res)-2
    if j == -1:
        c = 0
        p = 1
        for i in range(len(res)):
            c += p*res[i]
            p = p*3
        print(c)
    else:
        for i in range(0, j+1):
            res[i] = 0
        c = 0
        p = 1
        for i in range(len(res)):
            c += p*res[i]
            p = p*3
        print(c)
