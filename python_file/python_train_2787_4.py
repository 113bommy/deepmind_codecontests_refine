import sys
input = sys.stdin.readline

D=int(input())
C=[0]+list(map(int,input().split()))
S=[0]+[[0]+list(map(int,input().split())) for i in range(D)]
T=[0]+[int(input()) for i in range(D)]

ANS=0
LAST=[[0]*27 for i in range(D+1)]
for day in range(1,D+1):
    for j in range(1,27):
        LAST[day][j]=LAST[day-1][j]
    t=T[day]
    ANS+=S[day][t]
    LAST[day][t]=day

    for j in range(1,27):
        ANS-=C[j]*(day-LAST[day][j])

    #print(ANS)

M=int(input())
for tests in range(M):
    d,after_t=map(int,input().split())

    before_t=T[d]

    ANS+=S[d][after_t]-S[d][before_t]

    T[d]=after_t

    for day in range(d,D+1):
        if T[day]!=before_t:
            ANS+=C[before_t]*(day-LAST[day][before_t])
            LAST[day][before_t]=LAST[day-1][before_t]
            ANS-=C[before_t]*(day-LAST[day][before_t])
        else:
            break

    ANS+=C[after_t]*(d-LAST[d][after_t])
    LAST[d][after_t]=d

    for day in range(d+1,D+1):    
        if T[day]!=after_t:
            ANS+=C[after_t]*(day-LAST[day][after_t])
            LAST[day][after_t]=LAST[day-1][after_t]
            ANS-=C[after_t]*(day-LAST[day][after_t])

    print(ANS)
    
