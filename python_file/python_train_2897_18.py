# 最も単純にやると
# 盤面の移動のしかたはN^2通り
# それぞれに対して、対称行列かの判定はO(N^2)個の条件を確認する必要がある
# したがってO(N^4)である。間に合わない。
# しかし、対称行列であれば、1行1列を右下に移動しても対称行列である。
# これより、行またはだけを移動した場合について確認すれば良い。O(N^3)。

n = int(input())
masume = [input() for i in range(n)]

count = 0
for diff in range(n):
    flag = True
    for i in range(n):
        for j in range(i+1, n):
            if masume[(i+diff)%n][j] != masume[(j+diff)%n][i]:
                flag = False
                break
        if not flag:
            break
    count += flag

print(count * n)
