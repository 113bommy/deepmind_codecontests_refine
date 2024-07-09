import sys, math

def f1(c):
    if c in F1:
        return F1[c]
    else:
        pos = len(str(c))-1
        z = 0
        for j in range(pos+1):
            z = z + 9 *10**(j-1) * (j)
        #print(z)
    F1[c] = z + (pos+1)*(c - 10**(pos) +1)
    return F1[c]

def cerca1(n,a,b):
    #print(n,a,b)
    if n == f1(a):
        return a
    if n == f1(b):
        return b
    if (b-a)<=1:
        return a
    else:
        c = (a+b)//2
        if n <= f1(c):
            return cerca1(n,a,c)
        else:
            return cerca1(n,c,b)
    return


def f(c):
    if c in F:
        return F[c]
    else:
        pos = int(math.log10(c))
        z = 0
        for j in range(pos+1):
            z = z + 9 *10**(j-1) * (j)
    F[c] = L[pos] + (c-10**(pos)+1)*z + (pos+1)*(c - 10**(pos) +1+1)*(c - 10**(pos) +1)//2
    return F[c]
def cerca(n,a,b):
    if n == f(a):
        return a
    if n ==f(b):
        return b
    if (b-a)<=1:
        return a
    else:
        c = (a+b)//2
        if n <= f(c):
            return cerca(n,a,c)
        else:
            return cerca(n,c,b)
    return
sys.setmaxrecursiondepth = 30000
##sys.stdin = open("input.txt")
T = int(input())
F = {}
F1 = {}
l = 0
L = [l]
k = 1
n = 1
S = [0]
while l<10**18:
        z = 0
        for j in range(k):
            z = z + 9 *10**(j-1) * (j)
        l = L[-1] + 9 *10**(k-1) * z + k *( 9 * 10 **(k-1)+1)*(9*10**(k-1))//2
##        print ((10**k)-1)
        L.append(int(l))
        k = k + 1
####print (L)

for t in range(T):
   
    n = int(input())
##    a = L[0]
##    for j in range(1,len(L)):
##        if L[j-1]<=n and n <=L[j]:
##            pos = j-1
##            break
##    #vicino = cerca(n,10**(j-1)-1,10**j -1)
    vicino = cerca(n,1,1000000000)
    d = int(n - f(vicino))
    if d == 0:
        ris = str(vicino)[-1]
    else:
##        print (n,vicino, d, f1(vicino+1))
        vicino = cerca1(d,1,vicino+1)
##        print(vicino)
        d = int(d - f1(vicino-1))
##        print(d)
        if d>0:
            ris = (str(vicino)+str(vicino+1))[d-1]
        else:
            ris=str(vicino-1)[-1]
    print (ris)
    #print()
