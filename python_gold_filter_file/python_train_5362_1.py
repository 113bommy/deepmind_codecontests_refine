# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def give_me_fuckin_answers_bitch(x1,y1,x2,y2,vmax,a1x,a1y,a2x,a2y,mid,t):
    dx,dy = x2-x1,y2-y1
    if mid < t:
        z = (dy-a1y*mid)**2+(dx-a1x*mid)**2
    else:
        t1 = mid-t
        z = (dy-a1y*t-a2y*t1)**2+(dx-a1x*t-a2x*t1)**2
    if z <= vmax*vmax*mid*mid:
        return 1
    return 0

def main():
    x1,y1,x2,y2 = map(int,input().split())
    vmax,t = map(int,input().split())
    a1x,a1y = map(int,input().split())
    a2x,a2y = map(int,input().split())
    hi,lo,ans = 10**9,0,10**9
    for _ in range(100000):
        mid = (hi+lo)/2
        if give_me_fuckin_answers_bitch(x1,y1,x2,y2,vmax,a1x,a1y,a2x,a2y,mid,t):
            hi = mid
            ans = mid
        else:
            lo = mid
    print(ans)

# Fast IO Region
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
if __name__ == "__main__":
    main()