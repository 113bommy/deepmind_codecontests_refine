N,K=map(int,input().split())
A=list(map(int,input().split()))

DP=[False]*(K+1)
for i in range(1,K+1):
    for j in range(0,N):
        if A[j]<=i:
            DP[i]=DP[i] or not DP[i-A[j]]
        else:
            break

if DP[K]:
    print('First')
else:
    print('Second')

