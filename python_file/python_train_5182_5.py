N, K = list(map(int, input().split()))
P = list(map(int, input().split()))
C = list(map(int, input().split()))

res = -10**10

for i in range(N):
    j = i
    total = 0
    loop_values = []

    while True:
        j = P[j] - 1
        loop_values.append(C[j])
        total += C[j]
        if j == i:
            break
    
    loop_length = len(loop_values)
    point_sum = 0

    for j in range(loop_length):
        point_sum += loop_values[j]
        result_cand = point_sum

        if j+1 > K:
            break

        if total > 0:
            loop_num = (K - j - 1) // loop_length
            result_cand += total * loop_num
        
        if res < result_cand:
            res = result_cand

print(res)