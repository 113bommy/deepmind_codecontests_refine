# ------------------- fast io --------------------
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
 
# ------------------- fast io --------------------
for j in range(int(input())):
    n,m=map(int,input().split())
    matr=[]
    for s in range(n):
        string=[k for k in input()]
        matr.append(string)
    #turn every cell into 0
    #1 0     0 1  1 0  0 0
    #0 0 --->0 1, 1 1, 0 0
    ans=[]
    for s in range(n):
        for i in range(m):
            if matr[s][i]=="1":
                if s<n-1 and i<m-1:
                    o1=[(s+1,i+1),(s+1,i+2),(s+2,i+2)]
                    o2=[(s+1,i+2),(s+2,i+1),(s+1,i+1)]
                    o3=[(s+2,i+2),(s+2,i+1),(s+1,i+1)]
                    ans+=[o1,o2,o3]
                else:
                    if s==n-1 and i==m-1:
                        p1=[(s+1,i+1),(s+1,i),(s,i)]
                        p2=[(s,i),(s,i+1),(s+1,i+1)]
                        p3=[(s,i),(s,i+1),(s+1,i+1)]
                        ans+=[p1,p2,p3]
                    elif s==n-1:
                        q1=[(s+1,i+1),(s+1,i+2),(s,i+2)]
                        q2=[(s+1,i+1),(s+1,i+2),(s,i+1)]
                        q3=[(s+1,i+1),(s,i+1),(s,i+2)]
                        ans+=[q1,q2,q3]
                    else:
                        #i==m
                        w1=[(s+1,i+1),(s+1,i),(s+2,i)]
                        w2=[(s+1,i+1),(s+1,i),(s+2,i+1)]
                        w3=[(s+1,i+1),(s+2,i+1),(s+2,i)]
                        ans+=[w1,w2,w3]
    print(len(ans))
    for s in range(len(ans)):
        ops=ans[s]
        print(*ops[0],*ops[1],*ops[2])