N = int(input()) - 1

LARGE = 10**9+7

def ex_euclid(x, y):
    c0, c1 = x, y
    a0, a1 = 1, 0
    b0, b1 = 0, 1
 
    while c1 != 0:
        m = c0 % c1
        q = c0 // c1
 
        c0, c1 = c1, m
        a0, a1 = a1, (a0 - q * a1)
        b0, b1 = b1, (b0 - q * b1)
 
    return c0, a0, b0
# precompute
fac_list = [1]*(N+1)
fac = 1
for i in range(1, N+1):
    fac = (fac * i) % LARGE
    fac_list[i] = fac
    
fac_inv_list = [1]*(N+1)
for i in range(N+1):
    fac_inv_list[i] =  pow(fac_list[i], LARGE-2, LARGE)
    
def nCr(n, r):
    return (((fac_list[n] * fac_inv_list[r]) % LARGE) * fac_inv_list[n-r]) % LARGE

def pat(n, r):
    return (((fac_list[n] * fac_inv_list[r]) % LARGE) * fac_inv_list[n-r]) % LARGE


pat = 0
score = 0

for k in range(N+1):
    if k-1 >= N-k:
        res = (((fac_list[k-1]*fac_list[k]) % LARGE) * fac_inv_list[k-1-N+k]) % LARGE
        score = (score + (res - pat) * k) % LARGE
        # print(k, pat, res)
        pat = res
print(score)