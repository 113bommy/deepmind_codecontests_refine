K = str(input())
D = int(input())

N = len(K)

MOD = 10 ** 9 + 7

# if D == 1:
#     print (K)
#     exit()
# elif D == 2:
#     print (int(K) // 2)
#     exit()
# elif D == 5:
#     print (int(K) // 5)

dp0 = [[0] * D for _ in range(N + 1)]
dp1 = [0] * (N + 1)

for i in range(N):
    next_ = int(K[i])
    tmp = dp1[i]

    dp1[i + 1] = (tmp + next_) % D
    
    for j in range(next_):
        dp0[i + 1][(tmp + j) % D] += 1
    # print (dp0[i + 1])
    for j in range(D):
        for k in range(10):
            dp0[i + 1][(j + k) % D] += dp0[i][j]
    
    for j in range(D):
        dp0[i + 1][j] %= MOD


# for tmp in dp0:
#     print (tmp)

# print (dp1)


ans = dp0[N][0] - 1
if dp1[N] == 0:
    ans += 1

print (ans % MOD)