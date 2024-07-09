def main():
    s = input()
    n = len(s)
    k = int(input())
    # dp[使った回数][左端からの距離][左端]
    dp = [[[1]*(n-i) for i in range(n)] for _ in range(k+1)]

    if n == 1:
        print(1)
        return
    dp2 = dp[0][1]
    for i in range(n-1):
        if s[i] == s[i+1]:
            dp2[i] = 2
    if k > 0:
        for cnt in range(1, k+1):
            dp2 = dp[cnt][1]
            for i in range(n-1):
                dp2[i] = 2

    for cnt in range(k):
        dp2 = dp[cnt]
        dp4 = dp[cnt+1]
        for d in range(2, n):
            dp3 = dp2[d]
            dp5 = dp2[d-1]
            dp6 = dp2[d-2]
            dp7 = dp4[d]
            for left in range(n-d):
                right = left+d
                plus = (s[left] == s[right])*2
                dp3[left] = max(
                    dp3[left], dp5[left],
                    dp5[left+1], dp6[left+1]+plus)
                dp7[left] = max(
                    dp7[left], dp3[left], dp6[left+1]+2)
    dp2 = dp[k]
    for d in range(2, n):
        dp3 = dp2[d]
        dp4 = dp2[d-1]
        dp5 = dp2[d-2]
        for left in range(n-d):
            right = left+d
            plus = (s[left] == s[right])*2
            dp3[left] = max(
                dp3[left], dp4[left], dp4[left+1], dp5[left+1]+plus)
    print(dp[-1][-1][0])


main()
