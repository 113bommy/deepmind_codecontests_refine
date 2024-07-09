#入力を受け取る
N,K=map(int,input().split())
a=list(map(int,input().split()))
#DPの配列(少し余裕を持たせる)、Falseで初期化
DP=[False]*(K+10)
for i in range(1,K+1):
    for j in range(N):
        if i-a[j]>=0:
            DP[i] |= ~DP[i-a[j]] # ~は否定の意味(ビット反転)
            #ORなので, 一つでもFalseがあればTrueがはいる
if DP[K]:print("First")
else: print("Second")