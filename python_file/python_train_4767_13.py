import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    k,q=MI()
    dd=LI()
    for _ in range(q):
        n,x,m=MI()
        sall=spart=0
        zall=zpart=0
        for i,d in enumerate(dd):
            d%=m
            if i<(n-1)%k:
                spart+=d
                if d==0:zpart+=1
            sall+=d
            if d==0:zall+=1
        last=x%m+sall*((n-1)//k)+spart
        no=last//m
        print(n-1-no-zall*((n-1)//k)-zpart)

main()