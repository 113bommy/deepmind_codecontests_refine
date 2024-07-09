N, K = map(int, input().split())
A = [0] + sorted(map(int, input().split()))

# iを除いた左右の部分集合でK以上の数が作れるか
rdp_shift = [N + 1] * K  # rdp_shift[j] = (右からi個を使って部分和jを作れるような最初のi)
rdp_shift[0] = 0
rdp = [0] * K  # rdp[i][j] = (a(-1),...,a(-i)の部分和でjを作れるか)
rdp[0] = 1
for i in range(1, N + 1):
    rdp2 = [0] * K
    for j in range(K):
        if rdp[j] == 1:
            rdp2[j] = 1
            continue
        # print(j, -i, j - A[-i])
        # print(i, j)
        if j - A[-i] >= 0 and rdp[j - A[-i]] == 1:
            rdp2[j] = 1
            rdp_shift[j] = i
    rdp = rdp2

# print(rdp_shift, A)
ldp = [0] * K
ldp[0] = 1
S = [0] * (K + 1)
ans = 0
for i in range(1, N + 1):
    # ここで一つ一つチェックしている！！
    # A[i]が不要かチェック
    for j in range(K):
        # print(j)
        S[j + 1] = S[j]
        if rdp_shift[j] <= N - i:
            # print(S, rdp_shift, j, N - i, A[i])
            S[j + 1] += 1
            # print(S)
            # print(S, rdp_shift[j], N - i, i, j)
    no_need = True
    for lval in range(K):
        # print(ldp, lval)
        if ldp[lval] == 0:
            continue
        # print(K - A[i] - lval)
        rval = S[K - lval] - S[max(0, K - A[i] - lval)]
        # print(S, K - lval, K - A[i] - lval, rval)
        # print(rval, no_need, A[i], lval)
        # rval > 0というのはA[i]がなければ、K以上の集合を作れない場合があるということ
        if rval > 0:
            # print(S, K - lval, K - A[i] - lval, lval, rval, i, j, A[i])
            no_need = False
            break
    if no_need:
        ans += 1

    # ldp[i][:]の計算
    ldp2 = [0] * K
    for j in range(K):
        if ldp[j] == 1 or (j >= A[i] and ldp[j - A[i]] == 1):
            ldp2[j] = 1
    ldp = ldp2
print(ans)
