import time,math as mt,bisect,sys
from sys import stdin,stdout
from collections import deque
from fractions import Fraction
from collections import Counter
from collections import OrderedDict
pi=3.14159265358979323846264338327950
def II(): # to take integer input
    return int(stdin.readline())
def IO(): # to take string input
    return stdin.readline()
def IP(): # to take tuple as input
    return map(int,stdin.readline().split())
def L(): # to take list as input
    return list(map(int,stdin.readline().split()))
def P(x): # to print integer,list,string etc..
    return stdout.write(str(x)+"\n")
def PI(x,y): # to print tuple separatedly
    return stdout.write(str(x)+" "+str(y)+"\n")
def lcm(a,b): # to calculate lcm
    return (a*b)//gcd(a,b)
def gcd(a,b): # to calculate gcd
    if a==0:
        return b
    elif b==0:
        return a
    if a>b:
        return gcd(a%b,b)
    else:
        return gcd(a,b%a)
def readTree(): # to read tree
    v=int(input())
    adj=[set() for i in range(v+1)]
    for i in range(v-1):
        u1,u2=In()
        adj[u1].add(u2)
        adj[u2].add(u1)
    return adj,v
def bfs(adj,v): # a schema of bfs
    visited=[False]*(v+1)
    q=deque()
    while q:
        pass
def sieve():
    li=[True]*1000001
    li[0],li[1]=False,False
    for i in range(2,len(li),1):
        if li[i]==True:
            for j in range(i*i,len(li),i):
                li[j]=False
    prime=[]
    for i in range(1000001):
        if li[i]==True:
            prime.append(i)
    return prime
def setBit(n):
    count=0
    while n!=0:
        n=n&(n-1)
        count+=1
    return count
mx=10**7
spf=[mx]*(mx+1)
def SPF():
    spf[1]=1
    for i in range(2,mx+1):
        if spf[i]==mx:
            spf[i]=i
            for j in range(i*i,mx+1,i):
                if i<spf[j]:
                    spf[j]=i
    return
#####################################################################################
mod=10**9+7
def solve(i):
    n=II()
    a=input()
    b=input()
    if a==b:
        P(0)
        return
    else:
        for i in range(n):
            if ord(a[i])>ord(b[i]):
                P(-1)
                return
        move=0
        d={}
        for i in range(n):
            d[a[i]]=d.get(a[i],0)+1
        d2={}
        for i in range(n):
            d2[(a[i],b[i])]=d2.get((a[i],b[i]),0)+1
        used={}
        for i in range(20):
            curr=chr(97+i)
            #print(curr)
            if d.get(curr,-1)!=-1:
                for j in range(20):
                    char=chr(97+j)
                    if d2.get((curr,char),-1)!=-1 and curr!=char:
                        if used.get(curr,-1)!=-1:
                            d2[(used[curr],char)]=d2.get((curr,char),0)+1
                            del d2[(curr,char)]
                        else:
                            move+=1
                            used[curr]=char
                            d[char]=d.get(char,0)+1
                            del d2[(curr,char)]
        #P(d2)
        P(move)
        return


t=II()
for i in range(t):
    solve(i)

    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #