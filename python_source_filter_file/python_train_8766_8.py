import sys
import math
from collections import defaultdict,Counter
import bisect

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP1/output.txt",'w')
# sys.stdin=open("CP1/input.txt",'r')

# m=pow(10,9)+7
x1,y1,a1,a2,b1,b2=map(int,input().split())
xs,ys,t=map(int,input().split())
l=[[x1,y1]]
# start=0
for j in range(1,33):
    x=a1*l[j-1][0]+b1
    y=a2*l[j-1][1]+b2
    if len(str(x))>32 or len(str(y))>32:
        break
    l.append([x,y])
    # curr=abs(xs-x)+abs(ys-y)
    # if curr<mi:
    #     mi=curr
    #     start=j
# print(l)
ansf=0
t2=t
for i in range(len(l)):
    start=i
    mi=abs(xs-l[start][0])+abs(ys-l[start][1])
    ans=0
    if mi<=t:
        t-=mi
        ans+=1
        for j in range(start,0,-1):
            curr=abs(l[j][0]-l[j-1][0])+abs(l[j][1]-l[j-1][1])
            t-=curr
            if t<0:
                break
            ans+=1
    else:
        continue
    # print(ans,i)
    if t>0 and start+1!=len(l):
        t1=t
        ans1=0
        ans2=0
        for j in range(start+1,33):
            t+=mi
            mi=abs(xs-l[j][0])+abs(ys-l[j][1])
            t-=mi
            curr=abs(l[j][0]-l[j-1][0])+abs(l[j][1]-l[j-1][1])
            t-=curr
            if t<0:
                break
            ans1+=1
        mi=abs(l[start+1][0]-l[0][0])+abs(l[start+1][1]-l[0][1])
        t=t1
        t-=mi
        # print(t)
        if t>=0:
            ans2+=1
            for j in range(start+2,len(l)):
                curr=abs(l[j][0]-l[j-1][0])+abs(l[j][1]-l[j-1][1])
                t-=curr
                if t<0:
                    break
                ans2+=1
        ans+=max(ans1,ans2)
    # print(ans,i)
    ansf=max(ansf,ans)
    # print(ansf)
    t=t2
print(ansf)