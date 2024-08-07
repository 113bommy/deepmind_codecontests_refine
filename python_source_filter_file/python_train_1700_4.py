#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
#from bisect import bisect_left as bl                #c++ lowerbound bl(array,element)
#from bisect import bisect_right as br               #c++ upperbound br(array,element)
 
 
def main():
    # sys.stdin = open('input.txt', 'r')
    # sys.stdout = open('output.txt', 'w')
    for _ in range(int(input())):
        input()
        n,k=map(int,input().split(" "))
        temp=[x+1 for x in range(n)]
        ac=list(map(int,input().split(" ")))
        tm=list(map(int,input().split(" ")))
        comb=[]
        for x in range(len(tm)):
            comb.append([ac[x],tm[x]])
        comb.sort()
        stk=[]
        for x in range(k):
            if len(stk)==0:
                stk.append(comb[x])
            else:
                if stk[-1][1]+comb[x][0]-stk[-1][0]<=comb[x][1]:
                    continue
                else:
                    while len(stk)>0 and comb[x][1]+comb[x][0]-stk[-1][0]<=stk[-1][1]:
                        stk.pop()
                    stk.append(comb[x])
        ans=[1e12 for x in range(n+1)]
        done=set()
        for x in range(len(stk)):
            for y in range(stk[x][0],0,-1):
                ans[y]=min(ans[y],stk[x][1]+stk[x][0]-y)
                if x in done:
                    break
            for y in range(stk[x][0],n+1):
                ans[y]=min(ans[y],stk[x][1]+y-stk[x][0])
                if x+1<len(stk):
                    if y>=stk[x+1][0]: break
            done.add(stk[x][0])
        print(*ans[1:])

        

        




#-----------------------------BOSS-------------------------------------!
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

# endregion

if __name__ == "__main__":
    main()