import os,sys;from io import BytesIO, IOBase
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno();self.buffer = BytesIO();self.writable = "x" in file.mode or "r" not in file.mode;self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:break
            ptr = self.buffer.tell();self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE));self.newlines = b.count(b"\n") + (not b);ptr = self.buffer.tell();self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:os.write(self._fd, self.buffer.getvalue());self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file);self.flush = self.buffer.flush;self.writable = self.buffer.writable;self.write = lambda s: self.buffer.write(s.encode("ascii"));self.read = lambda: self.buffer.read().decode("ascii");self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
try:sys.stdin,sys.stdout=open('in.txt','r'),open('out.txt','w')
except:pass
ii1=lambda:int(sys.stdin.readline().strip()) # for interger
is1=lambda:sys.stdin.readline().strip() # for str
iia=lambda:list(map(int,sys.stdin.readline().strip().split())) # for List[int]
isa=lambda:sys.stdin.readline().strip().split() # for List[str]
mod=int(1e9 + 7);
from math import inf 
from collections import defaultdict as dd
# from math import *
# from collections import *;
# from collections import deque as dq 
# from string import ascii_lowercase,ascii_uppercase
# from functools import lru_cache
# sys.setrecursionlimit(500000)
# from bisect import bisect_left as bl,bisect_right as br
# from heapq import heapify,heappop,heappush
# def google(p):print('Case #'+str(p)+': ',end='')
###################### Start Here ######################
def main(t):
    n = ii1()
    arr = iia()
    s = sum(arr)
    N = n*(n+1)//2
    if s%N:print("NO");return 
    s = s//N 
    ans = []
    # a 3b 2c
    # 2a b 3c
    # 3a 2b c

    for i in range(n):
        ni = s - (arr[i] - arr[i-1])
        if ni%n:print("NO");return 
        if ni//n == 0:print("NO");return 
        ans.append(ni//n)
    print("YES")
    print(*ans)


    
     



if __name__ == "__main__":
    t = 1 
    t = ii1()
    for _ in range(t):
        main(_)
    
# snippets
# @f - for loop 
# @bfs - breadth first search 
# @Trie - Trie Data Structure 
# @rangeupdatepointquery - range update
# @DS - Disjoint Set
# @seive - generate seive