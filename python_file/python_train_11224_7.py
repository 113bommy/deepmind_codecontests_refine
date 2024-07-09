from collections import deque
N=int(input())
A=[int(i) for i in input().split()]
def f(K):
    L=deque()
    L.append([0,A[0]])
    for i in range(N-1):
        #print(L)
        if A[i]<A[i+1]:
            L.append([0,A[i+1]-A[i]])
            continue
        t=A[i]-A[i+1]
        while t-L[-1][1]>=0:
            t-=L[-1][1]
            L.pop()
            #print(L)
        L[-1][1]-=t
        #if L[-1][1]==0:
            #L.pop()
        if L[-1][0]!=K-1:
            if L[-1][1]==1:
                L[-1][0]+=1
            else:
                L[-1][1]-=1
                L.append([L[-1][0]+1,1])
        else:
            s=0
            while len(L)!=0 and L[-1][0]==K-1:
                s+=L[-1][1]
                L.pop()
            if len(L)==0:
                return False
            elif L[-1][1]==1:
                L[-1][0]+=1
                L.append([0,s])
            elif L[-1][1]!=1:
                L[-1][1]-=1
                L.append([L[-1][0]+1,1])
                L.append([0,s])
    #print(L)
    return True



mi=0
ma=2*10**5+1
while ma-mi>1:
    mid=(ma+mi)//2
    if f(mid):
        ma=mid
    else:
        mi=mid
print(ma)
