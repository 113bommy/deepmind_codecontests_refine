from math import ceil,sqrt,gcd
from collections import deque,defaultdict
def ii(): return int(input())
def si():return input()
def mi():return map(int,input().split())
def li():return list(mi())
t1=ii()
while(t1):
    t1-=1
    n=ii()
    s=si()
    t=si()
    k=0
    b=[]
    for i in range(n):
        if(s[i]!=t[i]):
            b.append(i)
    s=list(s)
    t=list(t)
    if(len(b)>2):
        print("NO")
    else:
        if(len(b)==0):
            print("YES")
        elif(len(b)==1):
            print("NO")
        else:
            p=s[b[0]]
            s[b[0]]=t[b[1]]
            t[b[1]]= p  
            f=0
            for i in range(n):
                if(s[i]!=t[i]):
                    print("NO")
                    f=1;
                    break
            if(f==0):
                print("YES")
        