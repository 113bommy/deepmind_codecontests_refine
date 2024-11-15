from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase
from sys import stdin,stdout
from collections import Counter
from math import ceil
from bisect import bisect_left 
from bisect import bisect_right
import math

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip


def main():
    n = ip()
    li = ai()
    x = sorted(li)
    for i in range(n-1):
        if li[i] != x[i]:
            for j in range(i+1,n):
             #   print(li[j],li[i])
                if li[j] == x[i] and x[j]==li[i]:
                    temp = li[i]
                    temp2 = li[j]
                    li[i] = temp2
                    li[j] = temp 
                    break
            break
 #   print(li)
    if x==li:
        print('YES')
    else:
        print('NO')

# 7 7 8 8 10 9
# 7 7 8 8 9 10

# 2 1 1 1 
# 1 1 1 2



    

# region fastio

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


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

ip = lambda: int(sys.stdin.readline().rstrip("\r\n"))
ai = lambda: list(map(int, sys.stdin.readline().split()))
ei = lambda: map(int, sys.stdin.readline().split())

# endregion

if __name__ == "__main__":
    main()