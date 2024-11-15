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

def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10 ** 18
MOD = 10**9+7

Ri = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()

n = int(ri())
a = Ri()

maxx,premaxx = -1,-1

dic = {}
for i in range(n):
    # print(premaxx, maxx)
    if a[i] > maxx:
        premaxx = maxx
        maxx = a[i]
        dic[maxx] = dic.get(maxx, 0)-1

    elif a[i] > premaxx:
        dic[maxx] = dic.get(maxx, 0)+1
        premaxx = a[i] 
    else:
        dic[a[i]]  = 0
if len(dic) == 0:
    print(1)
else:
    # pri/nt(dic)
    ansnum, maxx = -1,-10**18
    for i in dic:
        if dic[i] >= maxx:
            if dic[i] == maxx :
                if  i < ansnum:
                    ansnum = i
            else:
                ansnum = i
                maxx = dic[i]
    print(ansnum)