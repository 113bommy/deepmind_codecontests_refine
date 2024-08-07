 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   
 
# mandatory imports
import os
import sys
from io import BytesIO, IOBase
from math import log2, ceil, sqrt, gcd, log

# optional imports
# from itertools import permutations
# from functools import cmp_to_key  # for adding custom comparator
# from fractions import Fraction
# from collections import *
# from bisect import *
# from __future__ import print_function # for PyPy2
# from heapq import *
BUFSIZE = 8192


 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

 
g   = lambda : input().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
rr = lambda x : reversed(range(x)) 
mod = int(1e9)+7
inf = float("inf")


n, m, d = gil()
a = [(v, i) for i, v in enumerate(gil())]
a.sort()
fin = [0]*n
def isPos(x):
    i = 0
    while i+x < n:
        if a[i+x][0] - a[i][0]-1 < d:
            return False
        i += 1


    return True



l, r = 1, n
ans = n

while l <= r:
    mid = (l+r)//2
    if isPos(mid):
        r = mid - 1
        ans = mid
    else:
        l = mid + 1


for i in range(n):
    fin[a[i][1]] = 1 + (i%ans)

print(ans)
print(*fin)