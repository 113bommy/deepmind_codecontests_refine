from sys import  stdin, stdout
from math import *
from heapq import *
from collections import *
k=0
def p(t):
    global k
    Z=t%(2*k)
    if (Z<=k):
        return Z
    else:
        return (k-(Z%k))
def main():
    global k
    ntest=int(stdin.readline())
    for testcase in range(ntest):
        n,k,l=[int(x) for x in stdin.readline().strip().split()]
        d=[int(x) for x in stdin.readline().strip().split()]
        if (max(d)>l):
            stdout.write("No\n")
            continue
        avail=set([t for t in range(2*k)])
        for x in d:
            navail=set()
            for t in avail: 
                for z in range(1,2*k):
                    q=(t+z)%(2*k)
                    if ((x+p(t+z)) <= l ) and (q not in navail):
                        navail.add(q)
                    else:
                        break
            avail=navail
            if (len(navail)==0):
                break
        if (len(avail)==0):
            stdout.write("No\n")
            continue
        stdout.write("Yes\n")
    return 0
if __name__ == "__main__":
    main()