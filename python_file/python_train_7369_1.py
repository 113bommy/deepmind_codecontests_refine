import time
st_time=time.time()

from heapq import heappush, heappop, heapify
from collections import deque,defaultdict,Counter
import itertools
from itertools import permutations,combinations
import sys
import bisect
import string
import math
import random
def I():
    return int(input())
def MI():
    return map(int,input().split())
def LI():
    return [int(i) for i in input().split()]
def LI_():
    return [int(i)-1 for i in input().split()]
def show(*inp,end='\n'):
    if show_flg:
        print(*inp,end=end)
YN=['Yes','No']
mo=10**9+7
inf=float('inf')
ts=time.time()
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

show_flg=False
#show_flg=True

def dijkstra(edge,st):
    # initialize: def: d=dist(st,i), prev=[previous vertex in minimum path], q[]
    n=len(edge)
    d=[(0 if st==i else inf,i) for i in range(n)]
    prev=[0]*n
    q=[i for i in d]
    heapify(q)
    
    # calc
    while q:
        dist,cur=heappop(q)
        for dst,dist in edge[cur]:
            alt=d[cur][0]+dist
            if alt<d[dst][0]:
                d[dst]=(alt,dst)
                prev[dst]=cur
                heappush(q,(alt,dst))
    dist=[i for i,j in d]
    return dist,prev

V,E=MI()
g=[[] for _ in range(V+1)]
for i in range(E):
    u,v,d=MI()
    g[u].append((v,d))
    g[v].append((u,d))

mins=[[] for _ in range(V+1)]
prevs=[[] for _ in range(V+1)]
for i in range(1,V+1):
    min_dist,prev=dijkstra(g,i)
    mins[i]=min_dist
    prevs[i]=prev

#show('mins',mins)
#show('prevs',prevs)

T=I()
order=[0]*T
accor=[0]*T
order_time=[]
for i in range(T):
    n=I()
    accor[i]=accor[i-1]
    if n>0:
        oid,v=MI()
        order[i]=v
        accor[i]+=1
        #order_time[v].append(i)

#show('order',order)
order_at_shop=[] # stock (vertex, order_time)
item_at_car=[[] for _ in range(V+1)] # stock order time at each vertex
num_item_at_car=0

def ship():
    global num_item_at_car
#    show('order_at_shop',order_at_shop)
    while order_at_shop:
        v,t=order_at_shop.pop()
        item_at_car[v].append(t)
        num_item_at_car+=1
#        show('shipped',v,'at time',t)
#    show('item_at_car',item_at_car)

def deliver(v,deliver_t):
    global num_item_at_car
    d_p=0
#    show("delivered to",v,item_at_car[v])
    while item_at_car[v]:
        or_t=item_at_car[v].pop()
        num_item_at_car-=1
        d_p+=T**2-(deliver_t-or_t)**2
#    show("deliverPoint",d_p)
    return d_p

def stat_init():
    global order_at_shop
    global item_at_car
    global num_item_at_car
    order_at_shop=[] # stock (vertex, order_time)
    item_at_car=[[] for _ in range(V+1)] # stock order time at each vertex
    num_item_at_car=0

def rand_move(s,c):
    stat_init()
    
    move=[]
    state=0 # 0 on vertex, 1 on road
    reached=False # True if reached at final destination
    cur=1
    point=0
    
    #st=min(T//2,bisect.bisect(accor,V//2))
    #st=s+int(max( 100/(c),0 )*random.randint(0,T) )
    delta=int(T*math.exp(-c/50))
    minT=max(0,s-delta)
    maxT=min(int(0.95*T),s+delta)
    st=random.randint(minT,maxT)
    show('---------------',st)
    
    for t in range(T):
        v=order[t]
        if v!=0:
            #show('order!',v,'at',t)
            order_at_shop.append((v,t))
        if t<st:
            move.append(-1)
            #cur_order[order[t]]+=1
            ship()
        else:
            if state==0:
                # set final destination
                r=len(g[cur])
                dest,dist=g[cur][random.randint(0,r-1)]
                # end set final destination
                state=1
                move.append(dest)
                dist-=1
                if dist==0:
                    state=0
                    cur=dest
                    if dest==1: # 店で荷物を積載
                        ship()
                    else: # 配達完了
                        point+=deliver(dest,t)
            else:
                move.append(dest)
                dist-=1
                if dist==0:
                    state=0
                    cur=dest
    return point,st,move

def best_deliver(cur,now):
    global order_at_shop
    global item_at_car
    global num_item_at_car
    effc=0
    deliver_point=1
    # direct go
    for dest in range(2,V+1):
        if dest==cur:continue
        d=mins[cur][dest]
        rt=now+d
        alt=0
        for j in item_at_car[dest]:
            alt+=T**2-(rt-j)**2
        if alt/d>effc:
            effc=alt/d
            deliver_point=dest
    # turn to shop and go
    db=mins[cur][1]
    nx_item_at_car=[[] for i in range(1+V)]
    for order_v,t in order_at_shop:
        nx_item_at_car[order_v].append(t)
    for i in range(2,1+V):
        for t in item_at_car[i]:
            nx_item_at_car[i].append(t)
    for t in range(min(T-1,now+1),min(now+db+1,T)):
        v=order[t]
        if v!=0:
            nx_item_at_car[v].append(t)

    for dest in range(2,V+1):
        if dest==cur:continue
        dg=mins[1][dest]
        rt=now+dg+db
        alt=0
        for j in nx_item_at_car[dest]:
            alt+=T**2-(rt-j)**2
        if alt/d>effc:
            effc=alt/d
            deliver_point=1
        # generate root
        root=[]
        p=deliver_point
        while p!=cur:
            prev_p=prevs[cur][p]
            root.append((p,mins[p][prev_p]))
            p=prev_p
    return deliver_point,root

def greed_move():
    stat_init()
    
    move=[]
    state=0 # 0 on vertex, 1 on road
    reached=False # True if reached at final destination
    final_dest=1
    dest=1
    cur=1
    point=0
    
#    show('---------------start--')
    
    for t in range(T):
        v=order[t]
        if v!=0:
            #show('order!',v,'at',t)
            order_at_shop.append((v,t))
        if cur==1 and state==0:
            ship()
        if num_item_at_car==0 and cur==1 and state==0:
            move.append(-1)
            #cur_order[order[t]]+=1
            ship()
        else:
            if state==0:
                if dest==1: # 店で荷物を積載
                    ship()
                else: # 配達完了
                    point+=deliver(dest,t)

                if cur==final_dest:
                    # set final destination
                    final_dest,root=best_deliver(cur,t)
#                    show('root',root)
                    #dest=prevs[cur][final_dest]
                    if root:
                        dest,dist=root.pop()
                    else:
                        move.append(-1)
                        continue
                    if dest==cur:
                        dest=final_dest
                    #dist=mins[cur][dest]
#                    show('set f_dest and next',final_dest,dest)
                    # end set final destination
                else:
                    #dest=prevs[cur][final_dest]
                    dest,dist=root.pop()
                    if dest==cur:
                        dest=final_dest
                    #dist=mins[cur][dest]
                state=1
            else: # on road at teh begining
                0
            move.append(dest)
            dist-=1
            show('moving to',dest)
            if dist==0:
                state=0
                cur=dest
        
    return point,move

#for i in range(1,V+1):
    #show(i,g[i])

mode='rand'
mode='greed'
if mode=='rand':
    time_limit=29.5 # 1 = 1 sec
    time_limit=0.07
    now=time.time()
    p=-1
    s=T//2
    c=1
    while True:
        c+=1
        now=time.time()
        if now - st_time > time_limit:
            break
        cur_p,cur_st,cur_move=rand_move(s,c)
        if cur_p>p or p==-1:
            p=cur_p
            s=cur_st
            move=cur_move
#        show(cur_p,cur_st,cur_move)
    
#    show('result',p,s,move)
elif mode=='greed':
    point,move=greed_move()
#    show('point',point)
if len(move)<T:
    move+=[-1]*(T-len(move))
for i in move:
    print(i)


# recieve info
def interactive():
    
    for i in range(T):
    
    	# the number of new order
    	Nnew = int(input())
    	for j in range(Nnew):
    		new_id, dst = map(int, input().split())

    	# the number of items transfered into the car at time t.
    	Nput = int(input())

    	for j in range(Nput):
    		put_id = int(input())
    
    	# insert your code here to get more meaningful output
    	# you have to output a command here
    	print(move[i])
    	sys.stdout.flush()
    
    	vardict = input()
    	if vardict == 'NG':
    		sys.exit()
    
    	# the number of orders that have been delivered at time t.
    	Nachive = int(input())
    	for j in range(Nachive):
    		achive_id = int(input())
    
    return            
    
