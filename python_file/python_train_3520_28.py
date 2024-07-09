N = int(input())
A = list(map(int, input().split()))
dp = [[-1]*N for _ in range(N)]
for i in range(N):
    dp[i][i] = 0


def main(l, r):
    if dp[l][r] != -1:
        return dp[l][r]
    ret = 10**15
    for i in range(l, r):
        ret = min(ret, main(l, i)+main(i+1, r))
    ret += sum(A[l:r+1])
    dp[l][r] = ret
    return ret


print(main(0, N-1))