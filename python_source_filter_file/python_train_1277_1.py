#!/usr/bin/env python3

'''
Author: andyli
Time: 2020-09-08 23:09:31
'''

import os
from io import BytesIO, IOBase
import sys
from math import gcd


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        a.sort()
        d = a[-1]
        print(a[-1], end='')
        b = [False for i in range(n)]
        b[-1] = True
        for i in range(1, n):
            mx, p = 0, 0
            for j in range(n-2, -1, -1):
                if (not b[j]) and gcd(a[j], d) > mx:
                    mx = gcd(a[j], d)
                    p = j

            b[p] = True
            print(a[p], end='')
            d = gcd(d, a[p])
        print()
    return


# region fastio
BUFSIZE = 1048576


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
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
            self.newlines = b.count(b'\n') + (not b)
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
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
def input(): return sys.stdin.readline().rstrip('\r\n')

# endregion


if __name__ == '__main__':
    main()
