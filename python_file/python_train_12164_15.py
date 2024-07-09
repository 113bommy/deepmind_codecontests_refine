INF = 10**18

N = int(input())
T = list(map(int, input().split()))
V = list(map(int, input().split()))
V = [0] + V + [0]
R = [(0, 0)]*(N+2)
for i in range(1,N+1):
    R[i] = (R[i-1][1], R[i-1][1] + T[i-1])
R[N+1] = (R[N][1], R[N][1])
def velocity(i, x):
    if x < R[i][0]:
        return V[i]+R[i][0]-x
    elif R[i][0] <= x <= R[i][1]:
        return V[i]
    else:
        return V[i]+x-R[i][1]
ans = 0
dp = [0]*(R[N+1][1]*2+1)
for x in range(1, R[N+1][1]*2+1):
    mi = INF
    for i in range(N+2):
        mi = min(velocity(i, x/2), mi)
    dp[x] = mi
    ans += 0.25*(dp[x-1]+mi)
print(ans)
