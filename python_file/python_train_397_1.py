import math
H,W,K=map(int,input().split())

A=[]
S=[0,0]
for i in range(H):
    a=list(input())
    for j in range(W):
        if a[j]=="S":
            S=[i,j]
    A.append(a)

#print(A)
#print(S)
import sys
input=sys.stdin.readline
B=[[1000 for j in range(W)]for i in range(H)]

B[S[0]][S[1]]=0
ans=min(S[0],S[1],W-1-S[1],H-1-S[0])
#print(ans)
Q=[[0,S[0],S[1]]]


for i in range(10**6):
    if i==len(Q):
        break
    else:
        for j in range(1):
            if Q[i][1]>0 and B[Q[i][1]-1][Q[i][2]]==1000 and B[Q[i][1]][Q[i][2]]<K and A[Q[i][1]-1][Q[i][2]]==".":
                Q.append([Q[i][0]+1,Q[i][1]-1,Q[i][2]])
                B[Q[i][1]-1][Q[i][2]]=B[Q[i][1]][Q[i][2]]+1
                if ans>min(Q[i][1]-1,Q[i][2],H-1-(Q[i][1]-1),W-1-(Q[i][2])):
                    ans=min(Q[i][1]-1,Q[i][2],H-1-(Q[i][1]-1),W-1-(Q[i][2]))
                    
            if Q[i][2]>0 and B[Q[i][1]][Q[i][2]-1]==1000 and B[Q[i][1]][Q[i][2]]<K and A[Q[i][1]][Q[i][2]-1]==".":
                Q.append([Q[i][0]+1,Q[i][1],Q[i][2]-1])
                B[Q[i][1]][Q[i][2]-1]=B[Q[i][1]][Q[i][2]]+1
                if ans>min(Q[i][1],Q[i][2]-1,H-1-(Q[i][1]),W-1-(Q[i][2]-1)):
                    ans=min(Q[i][1],Q[i][2]-1,H-1-(Q[i][1]),W-1-(Q[i][2]-1))
                    
            if Q[i][1]<H-1 and B[Q[i][1]+1][Q[i][2]]==1000 and B[Q[i][1]][Q[i][2]]<K and A[Q[i][1]+1][Q[i][2]]==".":
                Q.append([Q[i][0]+1,Q[i][1]+1,Q[i][2]])
                B[Q[i][1]+1][Q[i][2]]=B[Q[i][1]][Q[i][2]]+1
                if ans>min(Q[i][1]+1,Q[i][2],H-1-(Q[i][1]+1),W-1-(Q[i][2])):
                    ans=min(Q[i][1]+1,Q[i][2],H-1-(Q[i][1]+1),W-1-(Q[i][2]))
                    
            if Q[i][2]<W-1 and B[Q[i][1]][Q[i][2]+1]==1000 and B[Q[i][1]][Q[i][2]]<K and A[Q[i][1]][Q[i][2]+1]==".":
                Q.append([Q[i][0]+1,Q[i][1],Q[i][2]+1])
                B[Q[i][1]][Q[i][2]+1]=B[Q[i][1]][Q[i][2]]+1
                if ans>min(Q[i][1],Q[i][2]+1,H-1-(Q[i][1]),W-1-(Q[i][2]+1)):
                    ans=min(Q[i][1],Q[i][2]+1,H-1-(Q[i][1]),W-1-(Q[i][2]+1))
#print(B)
#print(ans)
print(math.ceil(ans/K)+1)