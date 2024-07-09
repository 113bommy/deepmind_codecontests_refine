# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
from io import BytesIO, IOBase
import sys
from collections import defaultdict, deque, Counter
from math import sqrt, pi, ceil, log, inf, gcd, floor
from itertools import combinations
from bisect import *

def main():
    for _ in range(int(input())):
        n=int(input())
        s=list(input().rstrip())
        t=list(input().rstrip())
        a=[0]*26
        b=[0]*26
        for i in s:
            a[ord(i)-97]+=1
        for i in t:
            b[ord(i)-97]+=1
        f=0
        for i in range(26):
            if (a[i]+b[i])%2:
                f=1
                break
        if f:
            print("No")
        else:
            print("Yes")
            c=[]
            for i in range(n):
                if s[i]!=t[i]:
                    z=ord(s[i])-97
                    y=ord(t[i])-97
                    if a[z]!=1:
                        ind=i
                        for j in range(i+1,n):
                            if s[i]==s[j]:
                                ind=j
                                break
                        c.append([ind+1,i+1])
                        a[y]+=1
                        a[z]-=2
                        b[y]-=1
                        s[ind]=t[i]
                    elif b[y]!=1:
                        ind=i
                        for j in range(i+1,n):
                            if t[i]==t[j]:
                                ind=j
                                break
                        c.append([i+1,ind+1])
                        t[ind]=s[i]
                        a[z]-=1
                        b[z]+=1
                        b[y]-=2
                    else:
                        ind=0
                        for j in range(i+1,n):
                            if s[i]==t[j]:
                                ind=j
                                break
                        c.append([ind+1,ind+1])
                        c.append([ind+1,i+1])
                        x=ord(s[ind])-97
                        a[z]-=1
                        b[y]-=1
                        a[y]+=1
                        b[x]+=1
                        a[x]-=1
                        b[z]-=1
                        t[ind] = s[ind]
                        s[ind]=t[i]
                else:
                    z=ord(s[i])-97
                    a[z]-=1
                    b[z]-=1
            print(len(c))
            for i in c:
                print(*i)

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


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

if __name__ == "__main__":
    main()