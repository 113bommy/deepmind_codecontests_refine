import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

n = ni()
a = [ni() for _ in range(n)]

suma = sum(a)
MOD = 998244353

dp_rgb = [[0]*(suma+1) for _ in range(n+1)]
dp_gb = [[0]*(suma+1) for _ in range(n+1)]

dp_rgb[0][0] = 1
dp_gb[0][0] = 1

for i, ai in enumerate(a):
    for sm in range(suma+1):
        if sm + ai <= suma:
            dp_rgb[i+1][sm+ai] += dp_rgb[i][sm] % MOD
            dp_gb[i+1][sm+ai] += dp_gb[i][sm] % MOD
            
        dp_rgb[i+1][sm] += 2 * dp_rgb[i][sm] % MOD
        dp_gb[i+1][sm] += dp_gb[i][sm] % MOD
        
ng = 3 * sum(dp_rgb[n][-(-suma//2):]) % MOD
ok = 0 if suma%2 else 3*dp_gb[n][suma//2] % MOD

print((pow(3,n,MOD) - ng + ok) % MOD)