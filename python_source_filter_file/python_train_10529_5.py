#---------------------------iye ha aam zindegi---------------------------------------------
import math
import heapq,bisect
import sys
from collections import deque,defaultdict
from fractions import Fraction
mod=10**9+7
mod1=998244353
# ------------------------------warmup----------------------------
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


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
# -------------------game starts now----------------------------------------------------import math
class SegmentTree1:
    def __init__(self, data, default=9999999, func=lambda a, b: min(a , b)):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __delitem__(self, idx):
        self[idx] = self._default

    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def __len__(self):
        return self._len

    def query(self, start, stop):
        if start == stop:
            return self.__getitem__(start)
        stop += 1
        start += self._size
        stop += self._size

        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)

# -------------------game starts now----------------------------------------------------import math
class SegmentTree:
    def __init__(self, data, default=0, func=lambda a, b: a + b):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __delitem__(self, idx):
        self[idx] = self._default

    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def __len__(self):
        return self._len

    def query(self, start, stop):
        if start == stop:
            return self.__getitem__(start)
        stop += 1
        start += self._size
        stop += self._size

        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)
#-------------------------------iye ha chutiya zindegi-------------------------------------
class Factorial:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorials = [1, 1]
        self.invModulos = [0, 1]
        self.invFactorial_ = [1, 1]

    def calc(self, n):
        if n <= -1:
            print("Invalid argument to calculate n!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.factorials):
            return self.factorials[n]
        nextArr = [0] * (n + 1 - len(self.factorials))
        initialI = len(self.factorials)
        prev = self.factorials[-1]
        m = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = prev * i % m
        self.factorials += nextArr
        return self.factorials[n]

    def inv(self, n):
        if n <= -1:
            print("Invalid argument to calculate n^(-1)")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        p = self.MOD
        pi = n % p
        if pi < len(self.invModulos):
            return self.invModulos[pi]
        nextArr = [0] * (n + 1 - len(self.invModulos))
        initialI = len(self.invModulos)
        for i in range(initialI, min(p, n + 1)):
            next = -self.invModulos[p % i] * (p // i) % p
            self.invModulos.append(next)
        return self.invModulos[pi]

    def invFactorial(self, n):
        if n <= -1:
            print("Invalid argument to calculate (n^(-1))!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.invFactorial_):
            return self.invFactorial_[n]
        self.inv(n)  # To make sure already calculated n^-1
        nextArr = [0] * (n + 1 - len(self.invFactorial_))
        initialI = len(self.invFactorial_)
        prev = self.invFactorial_[-1]
        p = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = (prev * self.invModulos[i % p]) % p
        self.invFactorial_ += nextArr
        return self.invFactorial_[n]


class Combination:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorial = Factorial(MOD)

    def ncr(self, n, k):
        if k < 0 or n < k:
            return 0
        k = min(k, n - k)
        f = self.factorial
        return f.calc(n) * f.invFactorial(max(n - k, k)) * f.invFactorial(min(k, n - k)) % self.MOD
#--------------------------------------iye ha combinations ka zindegi---------------------------------
def powm(a, n, m):
    if a == 1 or n == 0:
        return 1
    if n % 2 == 0:
        s = powm(a, n // 2, m)
        return s * s % m
    else:
        return a * powm(a, n - 1, m) % m
#--------------------------------------iye ha power ka zindegi---------------------------------
def sort_list(list1, list2):
    zipped_pairs = zip(list2, list1)

    z = [x for _, x in sorted(zipped_pairs)]

    return z
#--------------------------------------------------product----------------------------------------
def product(l):
    por=1
    for i in range(len(l)):
        por*=l[i]
    return por
#--------------------------------------------------binary----------------------------------------
def binarySearchCount(arr, n, key):
    left = 0
    right = n - 1

    count = 0

    while (left <= right):
        mid = int((right + left) / 2)

        # Check if middle element is
        # less than or equal to key
        if (arr[mid] <= key):

            # At least (mid + 1) elements are there
            # whose values are less than
            # or equal to key
            count = mid + 1
            left = mid + 1

        # If key is smaller, ignore right half
        else:
            right = mid - 1

    return count
#--------------------------------------------------binary----------------------------------------
def countdig(n):
    c=0
    while(n>0):
        n//=10
        c+=1
    return c
def countGreater(arr, n, k):
    l = 0
    r = n - 1

    # Stores the index of the left most element
    # from the array which is greater than k
    leftGreater = n

    # Finds number of elements greater than k
    while (l <= r):
        m = int(l + (r - l) / 2)

        # If mid element is greater than
        # k update leftGreater and r
        if (arr[m] > k):
            leftGreater = m
            r = m - 1

        # If mid element is less than
        # or equal to k update l
        else:
            l = m + 1

    # Return the count of elements
    # greater than k
    return (n - leftGreater)
#--------------------------------------------------binary------------------------------------
def intersect(intervals):
    # First interval
    l = intervals[0][0]
    r = intervals[0][1]

    # Check rest of the intervals
    # and find the intersection
    for i in range(1, 2):

        # If no intersection exists
        if (intervals[i][0] > r or intervals[i][1] < l):
            return -1,-1

            # Else update the intersection
        else:
            l = max(l, intervals[i][0])
            r = min(r, intervals[i][1])

    return l,r
n,q=map(int,input().split())
a=[0]*n
b=[0]*n

tot=[0]*(n+1)
a1=[0]*q
b1=[0]*q
for i in range(q):
    a1[i],b1[i]=map(int,input().split())
    tot[a1[i]-1]+=1
    tot[b1[i]]-=1
for i in range(1,n+1):
    tot[i]+=tot[i-1]
ans=n
for i in range(n):
    if tot[i]==1:
        a[i]=1
    elif tot[i]==2:
        b[i]=1
    elif tot[i]==0:
        ans-=1
tr=0
w=[0]*n
w1=[0]*n
w[0]=a[0]
for i in range(1,n):
    w[i]=a[i]+w[i-1]
w=[0]+w
w1[0]=b[0]
for i in range(1,n):
    w1[i]=b[i]+w1[i-1]
w1=[0]+w1
for i in range(q):
    for j in range(i+1,q):
        l,r=intersect([[a1[i],b1[i]],[a1[j],b1[j]]])
        if l==-1 and r==-1:
            #e=ans-s.query(a1[i]-1,b1[i]-1)-s.query(a1[j]-1,b1[j]-1)
            e=ans-(w[b1[i]]-w[a1[i]-1])-(w[b1[j]]-w[a1[j]-1])
            tr=max(e,tr)
        else:
            a2=min(a1[i],a1[j])
            b2=max(b1[i],b1[j])
            #e=ans-s.query(a2-1,l-2)-s.query(r,b2-1)-s1.query(l-1,r-1)
            e = ans - (w[l-1] - w[a2 - 1]) - (w[b2-1] - w[r])-(w1[r]-w1[l-1])
            #print((w[l-1] - w[a2 - 1]),(w[b2-1] - w[r]),(w1[r]-w1[l-1]))
            tr=max(tr,e)
        #print(l,r,e,i,j)
print(tr)
