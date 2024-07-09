import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

N,mod=map(int,input().split())
EDGE=[list(map(int,input().split())) for i in range(N-1)]

if N==1:
    print(1)
    sys.exit()

EDGELIST=[[] for i in range(N+1)]
for x,y in EDGE:
    EDGELIST[x].append(y)
    EDGELIST[y].append(x)

SCORELIST=[[-1]*len(EDGELIST[i]) for i in range(N+1)]
PRODLIST=[[-1]*len(EDGELIST[i]) for i in range(N+1)]
PRODLIST_rev=[[-1]*len(EDGELIST[i]) for i in range(N+1)]
EDICT=dict()

for i in range(1,N+1):
    for j in range(len(EDGELIST[i])):
        EDICT[(i,EDGELIST[i][j])]=j

def dp(x,y):
    if SCORELIST[y][EDICT[(y,x)]]!=-1:
        return SCORELIST[y][EDICT[(y,x)]]

    ANS=1
    for to in EDGELIST[x]:
        if to==y:
            continue
        ANS=ANS*dp(to,x)%mod

    SCORELIST[y][EDICT[(y,x)]]=ANS+1   
    return ANS+1

def dp2(x,y):
    if PRODLIST[x][0]==-1:
        PRODLIST[x][0]=(SCORELIST[x][0])%mod
        for i in range(1,len(EDGELIST[x])):
            PRODLIST[x][i]=PRODLIST[x][i-1]*SCORELIST[x][i]%mod

        PRODLIST_rev[x][-1]=SCORELIST[x][-1]
        for i in range(len(EDGELIST[x])-2,-1,-1):
            PRODLIST_rev[x][i]=PRODLIST_rev[x][i+1]*SCORELIST[x][i]%mod

    if len(EDGELIST[x])==1:
        ANS=1
    elif EDICT[(x,y)]==0:
        ANS=PRODLIST_rev[x][1]
    elif EDICT[(x,y)]==len(EDGELIST[x])-1:
        ANS=PRODLIST[x][EDICT[(x,y)]-1]
    else:
        ANS=PRODLIST[x][EDICT[(x,y)]-1]*PRODLIST_rev[x][EDICT[(x,y)]+1]%mod

    SCORELIST[y][EDICT[(y,x)]]=ANS+1

for to in EDGELIST[1]:
    dp(to,1)

QUE=deque([1])
check=[0]*(N+1)

while QUE:
    x=QUE.pop()
    if check[x]==1:
        continue
    for to in EDGELIST[x]:
        if check[x]==0 or check[to]==0:
            dp2(x,to)
            QUE.append(to)
    check[x]=1

for i in range(1,N+1):
    print(PRODLIST[i][-1])