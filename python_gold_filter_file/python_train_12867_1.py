#------------------------template--------------------------#
import os
import sys
from math import *
from collections import *
from fractions import *
from bisect import *
from heapq import*
from io import BytesIO, IOBase
def vsInput():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
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
def value():return tuple(map(int,input().split()))
def array():return [int(i) for i in input().split()]
def Int():return int(input())
def Str():return input()
def arrayS():return [i for i in input().split()]

#-------------------------code---------------------------#
# vsInput()


n,x=value()

day=defaultdict(list)
voucher=[]


for i in range(n):
    l,r,c=value()
    d=r-l+1
    day[d].append((l,c))
    voucher.append((l,r,c))

minCost={}

for i in day:
    day[i].sort()
    minCost[i]=[inf]*(len(day[i]))
    
    m=inf
    for j in range(len(day[i])-1,-1,-1):
        m=min(day[i][j][1],m)
        minCost[i][j]=m


ans=inf
for l,r,c in voucher:
    cost=c
    need=x-(r-l+1)

    ind=bisect_left(day[need],(r+1,-1))
    if(ind!=len(day[need])):
        cost+=minCost[need][ind]
        ans=min(cost,ans)

if(ans==inf): ans=-1

print(ans)





    













