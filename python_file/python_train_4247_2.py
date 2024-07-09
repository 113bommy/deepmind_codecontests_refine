# F - I hate Matrix Construction

n = int(input())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
u = list(map(int, input().split()))
v = list(map(int, input().split()))
assert len(s) == len(t) == n
assert len(u) == len(v) == n

nbits = 64
AND = 0
OR  = 1

# conflict check
for i in range(n):
    for j in range(n):
        if (s[i] == AND and t[j] == OR  and  u[i] & ~v[j]) or \
           (s[i] == OR  and t[j] == AND and ~u[i] &  v[j]):
            print(-1)
            exit()

# 初期配列
A = [[u[i]] * n for i in range(n)]
for i in range(n):
    for j in range(n):
        if t[j] == AND:
            A[i][j] |= v[j]  # v[j]で1のビットは1
        else:
            A[i][j] &= v[j]  # v[j]で0のビットは0

# 1であるビット数を数える
ucount = [[0] * nbits for i in range(n)]
vcount = [[0] * nbits for j in range(n)]
for i in range(n):
    for j in range(n):
        for k in range(nbits):
            if A[i][j] & (1 << k):
                ucount[i][k] += 1
                vcount[j][k] += 1

def must_set(s, u, ucount, i, k):
    return s[i] == OR  and u[i] & (1 << k) and ucount[i][k] == 0
def must_clear(s, u, ucount, i, k):
    return s[i] == AND and u[i] & (1 << k) == 0 and ucount[i][k] == n

def find_and_set(t, v, vcount, k):
    "いずれかの列の第kビットを1にする"
    for j in range(n):
        if (t[j] == OR  and v[j] & (1 << k)) or \
           (t[j] == AND and v[j] & (1 << k) == 0 and vcount[j][k] < n - 1):
            return j
    raise Exception

def find_and_clear(t, v, vcount, k):
    "いずれかの列の第kビットを0にする"
    for j in range(n):
        if (t[j] == AND and v[j] & (1 << k) == 0) or \
           (t[j] == OR  and v[j] & (1 << k) and vcount[j][k] > 1):
            return j
    raise Exception

# 仕様通りでない箇所を修正
try:
    for i in range(n):
        for k in range(nbits):
            if must_set(s, u, ucount, i, k):
                # いずれかの列の第kビットを1にする
                j = find_and_set(t, v, vcount, k)
                A[i][j] |= 1 << k
                ucount[i][k] += 1
                vcount[j][k] += 1
            elif must_clear(s, u, ucount, i, k):
                # いずれかの列の第kビットを0にする
                j = find_and_clear(t, v, vcount, k)
                A[i][j] &= ~(1 << k)
                ucount[i][k] -= 1
                vcount[j][k] -= 1
    for j in range(n):
        for k in range(nbits):
            if must_set(t, v, vcount, j, k):
                i = find_and_set(s, u, ucount, k)
                A[i][j] |= 1 << k
                ucount[i][k] += 1
                vcount[j][k] += 1
            elif must_clear(t, v, vcount, j, k):
                i = find_and_clear(s, u, ucount, k)
                A[i][j] &= ~(1 << k)
                ucount[i][k] -= 1
                vcount[j][k] -= 1
except:
    print(-1)
    exit()

for i in range(n):
    print(' '.join(map(str, A[i])))
