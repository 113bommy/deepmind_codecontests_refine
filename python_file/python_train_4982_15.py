def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    mod = 10**9+7
    dp = [0]*k
    dp[0] = 1
    for i in range(n):
        aa = a[i]
        if aa >= k:
            continue
        for j in range(k-aa-1, -1, -1):
            dp[aa+j] = (dp[aa+j]+dp[j]) % mod
    b = [1]*n
    for i in range(n):
        if a[i] >= k:
            b[i] = 0
            continue
        aa = a[i]
        dp2 = [0]*k
        for j in range(aa):
            dp2[j] = dp[j]
        for j in range(aa, k):
            dp2[j] = (dp[j]-dp2[j-aa]) % mod
        for j in range(k-aa, k):
            if dp2[j] != 0:
                b[i] = 0
                break
    print(sum(b))


main()