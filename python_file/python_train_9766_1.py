import sys
input = sys.stdin.readline

mod = 10**9+7
def cmb(n, r, mod=mod):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

NN = 2*10**5 # 使うデータによって変える
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, NN + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

# 足す時は0~iまで一律に足し、返すのはi番目の値
class imosBIT():
    def __init__(self, N):
        self.N = N+1
        self.bit = [0 for _ in range(self.N+1)]
    
    def __str__(self):
        ret = []
        for i in range(1, self.N+1):
            ret.append(self.__getitem__(i))
        return "[" + ", ".join([str(a) for a in ret]) + "]"

    def __getitem__(self, i):
        i += 1
        s = 0
        while i <= self.N:
            s = (s + self.bit[i]) % mod
            i += i & -i
        return s

    def add(self, i, x):
        i += 1
        while i > 0:
            self.bit[i] = (self.bit[i] + x) % mod
            i -= i & -i
    
    # (i, N]に全てたす
    def addover(self, i, x):
        self.add(self.N-1, x)
        self.add(i, -x)

B, W = map(int, input().split())
N = B+W
Abit = imosBIT(N+1)
Bbit = imosBIT(N+1)
inv2 = pow(2, mod-2, mod)
t = inv2
for i in range(N):
    if i+1 >= W:
        Abit.addover(i, t*cmb(i, W-1)%mod)
    if i+1 >= B:
        Bbit.addover(i, t*cmb(i, B-1)%mod)
    t = t*inv2 % mod

for i in range(N):
    ans = (1 + Abit[i] - Bbit[i]) * inv2 % mod
    print(ans)