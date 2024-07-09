n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
# 辺の必要性
f = [[True] * n for _ in range(n)]
for k in range(n):
    for i in range(n):
        for j in range(n):
            # ワーシャルフロイドの更新が適用されたらダメ
            # 迂回路も最短コストなら直結路は不要
            if a[i][k] + a[k][j] < a[i][j]:
                print(-1)
                exit()
            elif a[i][k] + a[k][j] == a[i][j] and i != k and k != j:
                f[i][j] = False

ans = 0
for i in range(n):
    for j in range(n):
        if f[i][j]:
            ans += a[i][j]
ans //= 2
print(ans)