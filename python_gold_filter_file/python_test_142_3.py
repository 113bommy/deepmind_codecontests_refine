# -----------------FAST IO-------------------------
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


# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')
# sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
# input = lambda: sys.stdin.readline().rstrip("\r\n")

#---------------------------------------------------

import math
import collections
from itertools import permutations
from itertools import combinations


'''def is_prime(n):
    j=2
    while j*j<=n:
        if n%j==0:
            return 0
        j+=1
    return 1'''


'''def gcd(x, y):
    while(y):
        x, y = y, x % y
    return x'''

'''fact=[]
def factors(n) :
     
    i = 1
    while i <= math.sqrt(n):
         
        if (n % i == 0) :
             
            if (n / i == i) :
                fact.append(i)

            else :
    
                fact.append(i)
                fact.append(n//i)
        i = i + 1'''


'''def LCMofArray(a):
  lcm = a[0]
  for i in range(1,len(a)):
    lcm = lcm*a[i]//math.gcd(lcm, a[i])
  return lcm'''


def prob():
    
    # n = int(input())
    input()
    m,n=[int(x) for x in input().split()]
    # s = input()
    # l = [int(x) for x in input().split()]
    # a,s = [x for x in input().split()]

    ans = 0
    grid = []

    for i in range(m):
        l = [int(x) for x in input().split()]
        grid.append(l)

        p = sorted(l)
        ans = max(ans , p[-2])
        

    for i in range(n):
        c = 0

        for j in range(m):
            c = max(c , grid[j][i])

        # print(c , ans , i)
        ans = min(ans , c)

    print(ans)


# sys.stdin , sys.stdout = open('input.txt', 'r') , open('output.txt', 'w')
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

t=1
t=int(input())

for _ in range(0,t):
    # print("Case #" , end="")
    # print(_+1 , end=": ")
    prob()