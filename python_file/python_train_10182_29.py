import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    dp = [0] * (N+1)
    for i in range(1, N+1):
        gold, silver, copper = 0, 0, 0
        if i >= A[0]:
            gold = dp[i-A[0]] + B[0]
        if i >= A[1]:
            silver = dp[i-A[1]] + B[1]
        if i >= A[2]:
            copper = dp[i-A[2]] + B[2]
        dp[i] = max(i, gold, silver, copper)

    M = dp[N]
    dp = [0] * (M+1)
    for i in range(1, M+1):
        gold, silver, copper = 0, 0, 0
        if i >= B[0]:
            gold = dp[i-B[0]] + A[0]
        if i >= B[1]:
            silver = dp[i-B[1]] + A[1]
        if i >= B[2]:
            copper = dp[i-B[2]] + A[2]
        dp[i] = max(i, gold, silver, copper)

    return dp[M]


if __name__ == '__main__':
    print(main())
