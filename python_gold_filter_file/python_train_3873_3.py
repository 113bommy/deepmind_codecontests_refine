#------------------------------warmup----------------------------
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
 
#-------------------game starts now-----------------------------------------------------
for i in range(int(input())):
    n=int(input())
    s=list(input())
    t=list(input())
    d=dict()
    for j in range(n):
        if t[j] in d:
            d[t[j]]+=1
        else:
            d.update({t[j]:1})
        if s[j] in d:
            d[s[j]]+=1
        else:
            d.update({s[j]:1})
    f=0
    for j in d:
        if d[j]%2!=0:
            f=1
            break 
    if f==1:
        print("No")
    else:
        ans=[]
        print("Yes")
        for j in range(n):
            if s[j]!=t[j]:
                for k in range(j+1,n):
                    if s[k]==s[j]:
                        t[j],s[k]=s[k],t[j]
                        ans.append([k+1,j+1])
                        break
                    elif t[k]==s[j]:
                        t[k],s[k]=s[k],t[k]
                        ans.append([k+1,k+1])
                        t[j],s[k]=s[k],t[j]
                        ans.append([k+1,j+1])
                        break
        print(len(ans))
        for d in range(len(ans)):
            print(ans[d][0],ans[d][1])