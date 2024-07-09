"""
ABC076_D AtCoderExpress
まず区間に注目してEditorialみたいなグラフを思い描くことがきつかった。
そのうえで、区間Limitをバグなく実装するのが結構ポイント。
あとはVVあたりがバグってないかをPrintしながら見ていく形。
"""
N = int(input())
T = list(map(int,input().split()))
V = list(map(int,input().split()))
TMAX = sum(T)

TS = [0] * (N+1)
for i in range(N):
  TS[i+1] = TS[i] + T[i]
T_Left = TS[:N]
T_Right = TS[1:]
#print(T_Left,T_Right,V)

## これで下記がちゃんとつくれた。
# Tleft[i] <= t <= Tright[i] の間、 V[i]以下でなければいけない

# VV[tt] tt/2秒時の速度。両端がゼロ、という条件から初期値を生成する。
VV = [min(i*0.5, (TMAX*2-i) * 0.5) for i in range(TMAX*2+1)]
#print(VV)

# 区間iについて
for i in range(N):
  for tt in range(TMAX*2+1):
    VV[tt] = min(VV[tt], V[i] + max(0, (T_Left[i]*2 - tt) * 0.5, (tt-T_Right[i]*2) * 0.5))
#print(VV)
# 面積は両端がゼロであることから、速度合計を２で割る（0.5秒ごとだから）で出る。
# v-tグラフの面積を台形の面積で考えればよい。
print(sum(VV)/2)