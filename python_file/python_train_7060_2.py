import bisect
N=int(input())
A=list(map(int,input().split()))
B=[A[0]]
for i in range(1,N):
    B.append(A[i]+B[i-1])
#print(B)

ans=10**20
for x in range(2,N-1):
    #print(x)
    Q=[]
    q1=B[bisect.bisect_left(B,B[x-1]/2)]
    q2=B[x-1]-q1
    q3=B[bisect.bisect_left(B,B[x-1]/2)-1]
    q4=B[x-1]-q3
    if abs(q1-q2)<abs(q3-q4):
        Q.append(q1)
        Q.append(q2)
    else:
        Q.append(q3)
        Q.append(q4)
    q5=B[bisect.bisect_left(B,(B[N-1]+B[x-1])/2)]-B[x-1]
    q6=B[N-1]-q5-B[x-1]
    q7=B[bisect.bisect_left(B,(B[N-1]+B[x-1])/2)-1]-B[x-1]
    q8=B[N-1]-q7-B[x-1]
    
    if abs(q5-q6)<abs(q7-q8):
        Q.append(q5)
        Q.append(q6)
    else:
        Q.append(q7)
        Q.append(q8)
    if (max(Q)-min(Q))<ans:
        ans=(max(Q)-min(Q))
    #print(Q)
print(ans)