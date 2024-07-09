N = int(input())

E = []
es = [[] for _ in range(N)]
for j in range(N):
    s = input()
    e = []
    for i, c in enumerate(s):
        e.append(1 if c=="1" else float("inf"))
        if c=="1":
            es[i].append(j)
    E.append(e)

# http://prd-xxx.hateblo.jp/entry/2017/10/13/004256

#n個の頂点の色を初期化。0:未着色、1:黒、-1:白
colors = [0 for i in range(N)]

#頂点vをcolor(1 or -1)で塗り、再帰的に矛盾がないか調べる。矛盾があればFalse
def dfs(v,color):
    #今いる点を着色
    colors[v] = color
    #今の頂点から行けるところをチェック
    for to in es[v]:
        #同じ色が隣接してしまったらFalse
        if colors[to] == color:
            return False
        #未着色の頂点があったら反転した色を指定し、再帰的に調べる
        if colors[to] == 0 and not dfs(to, -color):
            return False
    #調べ終わったら矛盾がないのでTrue
    return True

if not dfs(0, 1):
    print(-1)
    exit()

for i in range(N):
    E[i][i] = 0

for k in range(N):
    for i in range(N):
        for j in range(N):
            E[i][j] = min(E[i][j], E[i][k]+E[k][j])

ans = 0
for e in E:
    ans = max(ans, max(e))
print(ans+1)
