N, K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))
ans = -float("inf")
for start in range(N):
    x = start
    cyc_score = []
    total_cyc_score = 0
    while True:
        x = P[x]-1
        cyc_score.append(C[x])
        total_cyc_score += C[x]
        if x == start: # 周期を検出
            break
    t = 0
    for i in range(len(cyc_score)):
        t += cyc_score[i]
        if i + 1 > K: break
        now_score = t
        if total_cyc_score > 0:
            e = int((K - i - 1) / len(cyc_score))
            now_score += total_cyc_score * e
        ans = max(ans, now_score)
print(ans)