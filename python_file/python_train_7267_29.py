N = int(input())
*A, = map(int, input().split())
C = [0]*4
for a in A:
    C[a] += 1

c1, c2, c3 = C[1:]
dp = [[[0]*(c1+c2+c3+1) for i in range(c2+c3+2)] for j in range(c3+2)]
for c in range(c3+1):
    M1 = c2+c3-c
    T = dp[c-1]
    S = dp[c]
    for b in range(M1+1):
        M2 = N-b-c
        X = S[b-1]; Y = S[b]
        Z = T[b+1]
        for a in range(M2==N, M2+1):
            r = N
            if a:
                r += a*Y[a-1]
            if b:
                r += b*X[a+1]
            if c:
                r += c*Z[a]
            Y[a] = r / (a+b+c)
print("%.10f" % dp[c3][c2][c1])