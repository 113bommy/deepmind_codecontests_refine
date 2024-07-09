# F - Bracket Sequencing

N = int(input())
L = []
R = []
for _ in range(N):
    S = list(str(input()))
    len_S = len(S)
    L_d = 0
    L_min_d = 0
    R_d = 0
    R_min_d = 0
    for i in range(len_S):
        if S[i] == '(':
            L_d += 1
        else:
            L_d -= 1
            L_min_d = min(L_min_d, L_d)
        if S[len_S-i-1] == ')':
            R_d += 1
        else:
            R_d -= 1
            R_min_d = min(R_min_d, R_d)
    if L_d >= 0:
        L.append((L_d, L_min_d))
    else:
        R.append((R_d, R_min_d))

L.sort(key=lambda x: x[1], reverse=True)
R.sort(key=lambda x: x[1], reverse=True)

ans = 'Yes'
l_now = 0
for d, min_d in L:
    if l_now + min_d < 0:
        ans = 'No'
        break
    else:
        l_now += d

r_now = 0
for d, min_d in R:
    if r_now + min_d < 0:
        ans = 'No'
        break
    else:
        r_now += d

if l_now != r_now:
    ans = 'No'

print(ans)