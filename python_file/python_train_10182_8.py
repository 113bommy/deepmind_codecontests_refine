#!/usr/bin/env python3

def main():
    N = int(input())
    gsba = list(map(int, input().split()))
    gsbb = list(map(int, input().split()))
    
    # ナップザック問題として解く
    w = gsba
    v = [gsbb[i]-gsba[i] for i in range(3)]
    dp = [0]*(N+1)

    for i in range(3):
        for j in range(N+1):
            if j >= w[i]:
                dp[j] = max(dp[j],dp[j-w[i]]+v[i])

    M = dp[-1] + N
    w = gsbb
    v = [gsba[i]-gsbb[i] for i in range(3)]
    dp = [0]*(M+1)

    for i in range(3):
        for j in range(M+1):
            if j >= w[i]:
                dp[j] = max(dp[j],dp[j-w[i]]+v[i])

    print(dp[-1] + M)

if __name__ == "__main__":
    main()