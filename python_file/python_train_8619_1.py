import sys;input=sys.stdin.readline

n,q=map(int, input().split())
event=[]
for _ in range(n):
    s,t,x=map(int,input().split())
    event.append((s-x-0.5,1,x))
    event.append((t-x-0.5,-1,x))
for i in range(q):
    event.append((int(input()),0,i))

event.sort()
is_stop=False
stop=set()
minstop=float('inf')
ans=[-1]*q
for t,e,x in event:
    if e > 0:
        stop.add(x)
        if x<minstop:
            minstop=x
            is_stop=True
    elif e<0:
        stop.remove(x)
        if minstop==x:
            is_stop=False
    elif len(stop)>0:
        if not is_stop:
             minstop=min(stop)
             is_stop=True
        ans[x]=minstop

print('\n'.join(map(str, ans)))