from collections import defaultdict
from math import log2
from bisect import bisect_left

import os
import sys
from io import BytesIO, IOBase
from types import GeneratorType

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
sys.setrecursionlimit(10**5)


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc








@bootstrap
def dfs(u):
    m=-float("inf")
    s=[]
    l=0
    for j in adj[u]:
        yield dfs(j)
        size[u]+=size[j]
        m=max(m,val[j])
        s.append(val[j])
        l+=1
    s.sort()
    curr=size[u]
    m1=curr
    for k in s:
        m1=min(m1,curr+k)
        curr+=-1



    if a[u]:
        val[u]=m

    else:
        val[u]=m1-size[u]


    if adj[u]==[]:
        size[u]=1
        val[u]=0
    yield



    yield





n=int(input())
adj=[[] for i in range(n+1)]
a=[0]+list(map(int,input().split()))
b=list(map(int,input().split()))
for i in range(n-1):
    adj[b[i]].append(i+2)

size=[0 for i in range(n+1)]
val=[-float("inf") for i in range(n+1)]
dfs(1)

print(size[1]+val[1])







