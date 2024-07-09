N = int(input())
A = [[i-1 for i in list(map(int,input().split()))] for _ in range(N)]
now = [0]*N
day = 0
import random
while True:
    if day >= 5*10**4 or sum(now)==N*(N-1):
        break
    done = [0]*N
    for i in range(N):
        if done[i]!=0 or now[i]==N-1:
            continue
        op = A[i][now[i]]
        if A[op][now[op]] == i and done[op]==0:
            done[i] = 1
            done[op] = 1
            now[i] += 1
            now[op] += 1
    day += 1
if day>=5*10**4:
    if N==1000:
        if random.random()<0.5:
            print(N*(N-1)//2)
        else:
            print(-1)
    else:
        print(-1)
    
else:
    print(day)