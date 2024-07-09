n, k = map(int, input().split())
p = list(map(int, input().split()))
c = list(map(int, input().split()))

max_score = -float('inf')

for i in range(n):
    loop_score_array = []
    loop_score = 0
    loop_len = 0
    pos = i
    while True:
        pos = p[pos] - 1
        loop_score += c[pos]
        loop_score_array.append(loop_score)
        loop_len+=1
        if pos == i:
            break
    for i, score in enumerate(loop_score_array):
        if k-i-1 < 0:
            continue
        loop_num = (k-i-1)//loop_len
        score_sum = score + max(0, loop_score)*loop_num
        max_score = max(score_sum, max_score)
print(max_score)