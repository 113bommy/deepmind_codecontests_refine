mod = 10**9+7
N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(60):
    cnt = 0
    for j in range(N):
        cnt += (A[j]>>i)&1
    ans = (ans+(((N-cnt)*cnt)%mod)*2**i)%mod
print(ans)