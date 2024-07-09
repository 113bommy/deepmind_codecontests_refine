import heapq
import sys
input=sys.stdin.readline

N,Q=map(int,input().split())
H=[]
for i in range(N):
    s,t,x=map(int,input().split())
    H.append([s-x,t-x,x])
H.sort()
#print(H)
P=0
q=[]
heapq.heapify(q)
for i in range(Q):
    n=int(input())
    #print("A",len(q))
    if P<N:
        while H[P][0]<=n:
            heapq.heappush(q,[H[P][2],H[P][0],H[P][1]])
            P+=1
            if P==N:
                break
    #print("B",i,len(q))
    if len(q)>0:
        while q[0][2]<=n:
            heapq.heappop(q)
            if len(q)==0:
                break
    if len(q)==0:
        print(-1)
    else:
        print(q[0][0])