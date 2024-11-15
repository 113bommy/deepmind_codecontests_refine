import os
import sys
from io import BytesIO, IOBase

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
##########################################################
#q.sort(key=lambda x:((x[1]-x[0]),-x[0]))
#from collections import Counter
#from fractions import Fraction
from bisect import bisect_left
from collections import Counter
#s=iter(input())
#from collections import deque
#ls=list(map(int,input().split()))
#for  in range(m):
#for _ in range(int(input())):
#n=int(input())
# n,k=map(int,input().split())
# arr=list(map(int,input().split()))
#for  i in range(int(input())):
#n=int(input())
#arr=sorted([(x,i) for i,x in enumerate(map(int,input().split()))])[::-1]
#print(arr)
#arr=sorted(list(map(int,input().split())))[::-1]

n,k=map(int,input().split())
if k>n**2:
    print(-1)
else:
    m=[[0]*n for i in range(n)]
    for i in range(n):
        if k<=0:
            break
        m[i][i]=1
        k-=1
        for j in range(i+1,n):
            if k>0:
                m[i][j]=1
                m[j][i]=1
                k-=2
    for i in m:
        print(*i)


