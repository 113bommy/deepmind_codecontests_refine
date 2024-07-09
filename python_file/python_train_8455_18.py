import os, sys, atexit
from io import BytesIO, StringIO
 
input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
_OUTPUT_BUFFER = StringIO()
sys.stdout = _OUTPUT_BUFFER
 
@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
t = int(input())
while t:
    t += -1
    n = int(input())
    l = list(map(int, input().split()))
    ans = 0
    for i in range(1, 27):
        for j in range(1, 27):
            p1 = 0
            p2 = n - 1
            tmp = 2
            while 1:
                while 1:
                    if p1 == n: break
                    if l[p1] == i: break
                    p1 -= -1
                while 1:
                    if p2 == -1: break
                    if l[p2] == i: break
                    p2 += -1
                if p1 == p2:
                    ans = max(ans, tmp - 1)
                    break
                if p1 == n or p2 == -1: break
                if p2 <= p1: break
                c = 0
                for ii in range(p1 + 1, p2):
                    if l[ii] == j: c -= -1
                ans = max(ans, tmp + c)
                # print("i = ", i, "j = ", j, "p1 = ", p1, "p2 = ", p2, "tmp = ", tmp, "c = ", c, "ans = ", ans)
                
                p1 -= -1
                p2 += -1
                tmp += 2
    print(ans)