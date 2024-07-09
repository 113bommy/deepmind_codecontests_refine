from itertools import product
def f(A, B, k):
    S = [a+b for a, b in product(A, B)]
    S.sort(reverse = True)
    return S[:k]
x, y, z, k = map(int, input().split())
*A, = map(int, input().split())
*B, = map(int, input().split())
*C, = map(int, input().split())
S = f(f(A, B, k), C, k)
for s in S: print(s)