def main():
    n = int(input())
    xyp = [list(map(int, input().split())) for _ in [0]*n]
    d = []

    def calc(seq):
        m = len(seq)
        dp = [[10**15]*(m+1) for _ in [0]*(m+1)]
        dp[0][0] = 0
        for i in range(m):
            s = seq[i][0]
            for j in range(i+1):
                temp = dp[j][0]
                for a, b in seq[:i+1]:
                    temp += min(abs(a), s-a)*b
                dp[j+1][i+1] = min(dp[j+1][i+1], temp)
                temp2 = 10**15
                for k in range(1, i+1):
                    temp = dp[j][k]
                    t = seq[k-1][0]
                    for a, b in seq[k:i+1]:
                        temp += min(abs(a), a-t, s-a)*b
                    temp2 = min(temp2, temp)
                dp[j+1][i+1] = min(dp[j+1][i+1], temp2)
        for i in range(m+1):
            for a, b in seq[:m]:
                dp[i][0] += abs(a)*b
            for k in range(1, m+1):
                t = seq[k-1][0]
                temp = 0
                for a, b in seq[k:m]:
                    temp += min(abs(a), a-t)*b
                dp[i][k] += temp
        for i in range(m+1):
            dp[i] = min(dp[i])
        dp += [0]*(n-m)
        return dp

    xyp.sort()
    for i in range(2**n):
        x_list, y_list = [], []
        for j in range(n):
            x, y, p = xyp[j]
            if i & 1:
                x_list.append([x, p])
            else:
                y_list.append([y, p])
            i >>= 1
        y_list.sort()
        d.append([calc(x_list), calc(y_list)])

    ans = [10**15]*(n+1)
    for x, y in d:
        for i in range(n+1):
            for j in range(n-i+1):
                ans[i+j] = min(ans[i+j], x[i]+y[j])
    for i in ans:
        print(i)


main()
