class Combi():
    def __init__(self, N, mod):
        self.power = [1 for _ in range(N+1)]
        self.rev = [1 for _ in range(N+1)]
        self.mod = mod
        for i in range(2, N+1):
            self.power[i] = (self.power[i-1]*i) % self.mod
        self.rev[N] = pow(self.power[N], self.mod-2, self.mod)
        for j in range(N, 0, -1):
            self.rev[j-1] = (self.rev[j]*j) % self.mod

    def C(self, K, R):
        if K < R:
            return 0
        else:
            return ((self.power[K])*(self.rev[K-R])*(self.rev[R])) % self.mod

    def P(self, K, R):
        if K < R:
            return 0
        else:
            return (self.power[K])*(self.rev[K-R]) % self.mod


P = int(input())
c = Combi(P-1, P)
A = list(map(int,input().split()))
ans = [0 for i in range(P)]
for i in range(P):
    if A[i] != 0:
        ans[0] += 1
        for j in range(P):
            ans[j] -= c.C(P-1, j)*pow(-i, P-1-j,P) 
for i in range(P):
    ans[i] %= P
print(*ans)