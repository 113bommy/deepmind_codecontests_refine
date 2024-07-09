N, K = [int(x) for x in input().split()]
P = [0] + [int(x) for x in input().split()]
C = [0] + [int(x) for x in input().split()]

max_score = max(C[1:])
for init in range(1, N + 1):   # 初めの場所をinitとする
    score = [0]  # k回移動後のスコア
    i = init
    for k in range(1, K + 1):
        i = P[i]  # k回移動後に着くところ
        score.append(score[-1] + C[i])
        max_score = max(max_score, score[k])
        if i == init:  # ループ検出
            loop_score = score[-1]
            loop_len = k
            if loop_score > 0:
                max_score = max(max_score, max(score[j] + loop_score * ((K - j) // loop_len) for j in range(1, loop_len + 1)))
            break

print(max_score)