MOD=10**9+7
N, M = map(int, input().split())

FCT = [1]
for i in range(1, M+1):
    FCT.append((FCT[-1] * i)%MOD)

def pmu(n, r, mod=MOD):
    return (FCT[n] * pow(FCT[n-r], mod-2, mod)) % mod

def cmb(n, r, mod=MOD):
    return (pmu(n, r) * pow(FCT[r], mod-2, mod)) % mod

def solve():
    # {the num of case B when A=range(1,N+1)} x {permutation of A}
    # use inclusion-exclusion principle against former
    ans = 0
    for i in range(N+1):
        cp = (cmb(N, i) * pmu(M-i, N-i))%MOD
        ans = (ans + (1 if i%2==0 else -1) * cp) % MOD
    return (ans * pmu(M, N)) % MOD

if __name__ == "__main__":
    print(solve())
