N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

def solve(n,fr,to):
    rates = [(f,t) for f,t in zip(fr,to) if f < t]
    rates.sort()
    if not rates:
        return n
    dp = [i for i in range(n+1)]
    for f,t in rates:
        for i in range(f,n+1):
            dp[i] = max(dp[i], dp[i-f] + t)
    return dp[-1]

n = solve(N,A,B)
print(solve(n,B,A))