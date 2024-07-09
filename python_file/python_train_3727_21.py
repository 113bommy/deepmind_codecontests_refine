#C問題
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

ans = 0
div = 0
flag = 1
while flag == 1:
    flag = 0
    for i in range(N):
        if B[i]-B[i-1]-B[(i+1)%N] >= A[i]:
            div = (B[i]-A[i])//(B[i-1]+B[(i+1)%N])
            B[i] -= (B[i-1]+B[(i+1)%N])*div
            ans+=div
            flag = 1
            
print(ans if A == B else -1)