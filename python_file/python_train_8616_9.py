k = int(input())
s = input()
p = 1000000007
x = 0
inv = [0, 1]
fact = [1, 1]
factinv = [1, 1]
for i in range(2, k+len(s)+1):
    inv.append(-inv[p%i]*(p//i)%p)
    fact.append(fact[-1]*i%p)
    factinv.append(factinv[-1]*inv[-1]%p)
def cmb(n, r, p):
    return fact[n]*factinv[r]*factinv[n-r]%p
a = [1]
b = [1]
for _ in range(k):
    a.append(a[-1]*25%p)
    b.append(b[-1]*26%p)
for i in range(k+1):
    x = (x+a[i]*b[k-i]*cmb(i+len(s)-1, i, p))%p
print(x)