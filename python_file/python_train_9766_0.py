def cmb(n, r):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

mod = 10**9+7 #出力の制限
N = 2*10**5
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

b,w=map(int,input().split())
x=0
y=0
for i in range(1,b+w+1):
  x=(x*2+cmb(i-2,b-1))%mod
  y=(y*2+cmb(i-2,w-1))%mod
  print((mod+pow(2,i-1,mod)-x+y)*pow(pow(2,i,mod),mod-2,mod)%mod)