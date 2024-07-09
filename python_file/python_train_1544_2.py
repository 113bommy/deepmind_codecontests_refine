N, X = map(int, input().split())
x_list = list(map(int, input().split()))
x_cumsum = [0]*N

cum = 0
for i in range(N):
    cum += x_list[i]
    x_cumsum[i] = cum
    
res = cum*5 + 2*N*X
for n in range(1, N):
    res_temp = (N+n)*X
    
    for i in range(N // n):
        if i == 0:
            c = 5
        else:
            c = 2*i+3
        if N-1-(i+1)*n == -1:
            res_temp += c * x_cumsum[N-1-i*n]
        else:
            res_temp += c * (x_cumsum[N-1-i*n] - x_cumsum[N-1-(i+1)*n])
    i = N // n
    c = 2*i+3
    if N % n != 0:
        res_temp += c * x_cumsum[N % n - 1]
    res = min(res, res_temp)
    
print(res)