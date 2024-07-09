K = int(input())
S = input()
s = len(S)
base = 10 ** 9 + 7

L26 = [ 1 for i in range(K+1)] # 26^i mod base 
for i in range(K):
  L26[i+1] = (L26[i] * 26) % base

T1 = 1
T2 = 1
ans = 0
for i in range( s, s+K+1):
  T3 = L26[K + s - i]
  #T4 = pow(26, K + s - i, base)
  #print(T3, T4)
  p = (T1 * T2) % base
  p = (p * T3) % base
  ans += p
  ans %= base
  #print(ans, T1, T2, T3)
  T1 *= 25
  T1 %= base
#  T2 = (T2 * i ) // (i+1-s) # T2 = (i, s-1) = (i-1, s-1) * i // (i+1-s)
  T2 *= i
  T2 %= base
  T2 *= pow(i+1-s, base-2, base)
  T2 %= base
  
print(ans % base)