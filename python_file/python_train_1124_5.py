N, Q = map(int, input().split())
S = input()
Query = [list(input().split()) for i in range(Q)]


# 番兵を設置
S = 'x' + S + 'x'

# 左から何番目のゴーレムまで消えるか二分探索
ok, ng = 0, N + 1
while abs(ok - ng) > 1:
    m = (ok + ng) // 2
    x = (ok + ng) // 2

    for t, d in Query:
        if S[x] != t:
            continue

        if d == 'R':
            x += 1
        if d == 'L':
            x -= 1

        if x == 0:
            ok = m
            break
    else:
        ng = m
Left_ans = ok

# 右から何番目のゴーレムまで消えるか二分探索
ok, ng = N + 1, 0
while abs(ok - ng) > 1:
    m = (ok + ng) // 2
    x = (ok + ng) // 2

    for t, d in Query:
        if S[x] != t:
            continue

        if d == 'R':
            x += 1
        if d == 'L':
            x -= 1

        if x == N + 1:
            ok = m
            break
    else:
        ng = m
Right_ans = ok

print(N - min(N, Left_ans + (N + 1 - Right_ans)))
