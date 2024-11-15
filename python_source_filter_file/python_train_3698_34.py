from collections import Counter
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
#for _ in range(int(input())):
#import math
import sys
# from collections import deque
#from collections import Counter
# ls=list(map(int,input().split()))
# for i in range(m):
# for i in range(int(input())):
#n,k= map(int, input().split())
#arr=list(map(int,input().split()))
#n=sys.stdin.readline()
#n=int(n)
#n,k= map(int, input().split())
#arr=list(map(int,input().split()))
import sys
import math
#for i in range(int(input())):
n=int(input())
s=input()
c=Counter(s)
ls=[]
for i in c:
    ls.append(i)
ana="RGB"
if "R" in s and "G" in s and "B" in s:
    print("RGB")
elif s=="R"*n or s=="B"*n or  s=="G"*n:
    print(s[0])
elif c[ls[0]]>=2 and c[ls[1]]>=2:
    print("BGR")
elif c[ls[0]]>=2 or c[ls[1]]>=2:
    if c[ls[0]]>=2:
        if ls[0]=="B":
            print("GR")
        elif ls[0]=="R":
            print("BG")
        else:
            print("BR")
    else:
        if ls[1]=="B":
            print("GR")
        elif ls[1]=="R":
            print("BG")
        else:
            print("BR")
else:
    if "R" not in s:
        print("R")
    elif "G" not in s:
        print("G")
    else:
        print("B")