"""

重要度はlかuしかとらないと考えてよい
高橋君のほうが青木君より低い点数を取ると決めた科目に対してはl、それ以外はuと定める
それぞれのテストの点数の差をdとして、Σ[a>=b](d*u) - Σ[a<b](d*l) >= 0 を満たす
最小のΣaを求める
→各iについて、biまではli個ずつ減らすことができ、それより多く減らす場合はXを超えない範囲で
 ui個ずつ減らすことができる
→heapqでできそう
 単純なheapqだと、例えば一つのテストの中でlとuの値の差がとても大きい時に
 正しい答えが出せない
→二分探索

"""
import sys
input = sys.stdin.readline

n, x = map(int, input().split())
BLU = [list(map(int, input().split())) for _ in range(n)]
SBLU = sorted([(b*l+(x-b)*u, b, l, u) for b, l, u in BLU], reverse=True)
S, B, L, U = zip(*SBLU)
M = sum([b*l for b, l, u in BLU])

def select(q, r):
  f = sum(S[:q+1])
  for i in range(n):
    temp = f - S[min(i, q)]
    temp += L[i]*min(B[i], r) + U[i]*max(r-B[i], 0)
    if temp>=M:
      return True
  return False


ng = -1
ok = sum(B)
while ok-ng > 1:
  mid = (ok+ng)//2
  q, r = divmod(mid, x)
  if select(q, r):
    ok = mid
  else:
    ng = mid
print(ok)