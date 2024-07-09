def solve(n, aaa):
    dp = [[-1] * n for _ in range(n)]
    dp_max = [-1] * n
    ans = 0

    a0, a1 = sorted(aaa[:2])
    dp[a0][a1] = 0
    dp_max[a0] = 0
    dp_max[a1] = 0

    for k in range(n - 1):
        a0, a1, a2 = sorted(aaa[2 + 3 * k:5 + 3 * k])
        if a0 == a1 and a1 == a2:
            ans += 1
            continue

        dp_max_max = max(dp_max)
        update_tasks = []

        if a0 == a1 or a1 == a2:
            rev = a1 == a2
            if rev:
                a0, a2 = a2, a0

            for b in range(n):
                c, d = min(a0, b), max(a0, b)
                e, f = min(a2, b), max(a2, b)
                update_tasks.append((e, f, dp_max[b]))
                if dp[c][d] != -1:
                    update_tasks.append((e, f, dp[c][d] + 1))

            update_tasks.append((a0, a0, dp_max_max))
            if dp[a2][a2] != -1:
                update_tasks.append((a0, a0, dp[a2][a2] + 1))

            if rev:
                update_tasks.append((a2, a0, dp_max_max))
            else:
                update_tasks.append((a0, a2, dp_max_max))

        else:
            update_tasks.append((a0, a1, dp_max_max))
            update_tasks.append((a0, a2, dp_max_max))
            update_tasks.append((a1, a2, dp_max_max))
            if dp[a0][a0] != -1:
                update_tasks.append((a1, a2, dp[a0][a0] + 1))
            if dp[a1][a1] != -1:
                update_tasks.append((a0, a2, dp[a1][a1] + 1))
            if dp[a2][a2] != -1:
                update_tasks.append((a0, a1, dp[a2][a2] + 1))

            for b in range(n):
                b_max = dp_max[b]
                for a in (a0, a1, a2):
                    c, d = min(a, b), max(a, b)
                    update_tasks.append((c, d, b_max))

        for a, b, c in update_tasks:
            dp[a][b] = max(dp[a][b], c)
            dp_max[a] = max(dp_max[a], c)
            dp_max[b] = max(dp_max[b], c)

    a = aaa[-1]
    dp[a][a] += 1

    return max(map(max, dp)) + ans


n = int(input())
aaa = [a - 1 for a in map(int, input().split())]
ans = solve(n, aaa)
print(ans)
