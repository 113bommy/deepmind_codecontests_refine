from __future__ import division, print_function
# import threading
# threading.stack_size(2**27)
# import sys
# sys.setrecursionlimit(10**4)
from sys import stdin, stdout
import bisect            #c++ upperbound
import math
import heapq
i_m=9223372036854775807
def modinv(n,p):
    return pow(n,p-2,p)
def cin():
    return map(int,sin().split())
def ain():                           #takes array as input
    return list(map(int,sin().split()))
def sin():
    return input()
def inin():
    return int(input())
import math  
def GCD(x, y): 
    x=abs(x)
    y=abs(y)
    if(min(x,y)==0):
        return max(x,y)
    while(y): 
        x, y = y, x % y 
    return x 
def Divisors(n) : 
    l = []  
    for i in range(1, int(math.sqrt(n) + 1)) :
        if (n % i == 0) : 
            if (n // i == i) : 
                l.append(i) 
            else : 
                l.append(i)
                l.append(n//i)
    return l
prime=[]
def SieveOfEratosthenes(n): 
    global prime
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
    f=[]
    for p in range(2, n): 
        if prime[p]: 
            f.append(p)
    return f
q=[]       
def dfs(n,d,v,c):
    global q
    v[n]=1
    if n not in d:
        return v
    x=d[n]
    q.append(n)
    j=c
    for i in x:
        if i not in v:
            v=dfs(i,d,v,c+1)
            # print(f)
    return v

        
"""*******************************************************"""
def main():
    t=inin()
    for _ in range(t):
        n=inin()
        n=2*n
        print(1/math.sin(math.pi / n))


    
    
######## Python 2 and 3 footer by Pajenegod and c1729
 
# Note because cf runs old PyPy3 version which doesn't have the sped up
# unicode strings, PyPy3 strings will many times be slower than pypy2.
# There is a way to get around this by using binary strings in PyPy3
# but its syntax is different which makes it kind of a mess to use.
 
# So on cf, use PyPy2 for best string performance.
 
py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange
 
import os, sys
from io import IOBase, BytesIO
 
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
        self.seek((self.tell(), self.seek(0,2), super(FastIO, self).write(s))[0])
        return s
 
    def read(self):
        while self._fill(): pass
        return super(FastIO,self).read()
 
    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
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
            self.write = lambda s:self.buffer.write(s.encode('ascii'))
            self.read = lambda:self.buffer.read().decode('ascii')
            self.readline = lambda:self.buffer.readline().decode('ascii')
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')
 
# Cout implemented in Python
import sys
class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
cout = ostream()
endl = '\n'
 
# Read all remaining integers in stdin, type is given by optional argument, this is fast
def readnumbers(zero = 0):
    conv = ord if py2 else lambda x:x
    A = []; numb = zero; sign = 1; i = 0; s = sys.stdin.buffer.read()
    try:
        while True:
            if s[i] >= b'R' [0]:
                numb = 10 * numb + conv(s[i]) - 48
            elif s[i] == b'-' [0]: sign = -1
            elif s[i] != b'\r' [0]:
                A.append(sign*numb)
                numb = zero; sign = 1
            i += 1
    except:pass
    if s and s[-1] >= b'R' [0]:
        A.append(sign*numb)
    return A
 
# threading.Thread(target=main).start()
if __name__== "__main__":
  main()