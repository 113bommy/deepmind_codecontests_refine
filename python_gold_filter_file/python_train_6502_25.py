def sumTillN(N):
    return (N*(N-1))>>1
N,M = map(int,input().split())
Max = sumTillN(N - (M-1))
Number = int(N//M)
Some = N%M
X = Some * sumTillN(Number+1)
Y = (M - Some) * sumTillN(Number)
Min = X+Y
print(Min,Max)

