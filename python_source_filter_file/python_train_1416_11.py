import sys
import os
from io import IOBase, BytesIO
# import heapq
import math
# import collections
# import itertools
# import bisect
mod = 10 ** 9 + 7
pie = 3.1415926536
# import resource
# resource.setrlimit(resource.RLIMIT_STACK, [0x100000000, resource.RLIM_INFINITY])
# import threading
# threading.stack_size(2**27)
# import sys
# sys.setrecursionlimit(10**6)
# fact=[1]
# for i in range(1,1000001):
#    fact.append((fact[-1]*i)%mod)
# ifact=[0]*1000001
# ifact[1000000]=pow(fact[1000000],mod-2,mod)
# for i in range(1000000,0,-1):
#    ifact[i-1]=(i*ifact[i])%mod
# from random import randint as rn
# from Queue import Queue as Q


def modinv(n, p):
    return pow(n, p-2, p)


def ncr(n, r, p):  # for using this uncomment the lines calculating fact and ifact
    t = ((fact[n])*((ifact[r]*ifact[n-r]) % p)) % p
    return t


def ain():  # takes array as input
    return list(map(int, sin().split()))


def sin():
    return input().strip()


def GCD(x, y):
    while(y):
        x, y = y, x % y
    return x


def read2DIntArray(row, col):
    arr = []
    for i in range(0, row):
        temp = list(map(int, sin().split()))
        arr.append(temp)

    return arr


def read2DCharArray(row, col):
    arr = []
    for i in range(0, row):
        temp = str(sin())
        arr.append(temp)

    return arr


# Smallest number by rearranging digits of a given number (without trailing zeros):-


def smallestNumber(n):
    lst = list(str(n))
    lst.sort()

    tmp = ""
    for i, n in enumerate(lst):
        if (n != '0'):
            tmp = lst.pop(i)
            break

    return str(tmp) + ''.join(lst)


"""***************************************************************************************"""


def main():
    s = sin()
    hh, mm = map(int, s.split(":"))
    if hh > 12:
        hh = hh - 12
    m = mm * 6
    h = (hh * 30) + ((mm / 60) * 30)

    if hh == 12:
        h = 360 - h

    print(str(h) + " " + str(m))


"""***************************************************************************************"""

# Python 2 and 3 footer by Pajenegod and c1729
py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange


BUFSIZE = 8192


class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0, 2),
                   super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill():
            pass
        return super(FastIO, self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill()
            self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s: self.buffer.write(s.encode('ascii'))
            self.read = lambda: self.buffer.read().decode('ascii')
            self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)


def input(): return sys.stdin.readline().rstrip('\r\n')


if __name__ == '__main__':
    main()
# threading.Thread(target=main).start()
