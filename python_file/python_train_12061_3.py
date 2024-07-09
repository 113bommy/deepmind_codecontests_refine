N, W = map(int, input().split())
vs = [[] for _ in range(4)]
w1, v1 = map(int, input().split())
vs[0].append(v1)
for i in range(N - 1):
    w, v = map(int, input().split())
    vs[w - w1].append(v)
#print(vs)
for i in range(4):
    vs[i].sort()
#print(vs)
ans = 0
for i in range(N + 1):
    if i * w1 > W:
        break
    if i == 0:
        si = 0
    else:
        si = sum(vs[0][-i:])
    for j in range(N + 1 - i):
        if i * w1 + j * (w1 + 1) > W:
            break
        sj = si
        if j > 0:
            sj += sum(vs[1][-j:])
        for k in range(N + 1 - i - j):
            if i * w1 + j * (w1 + 1) + k * (w1 + 2) > W:
                break
            sk = sj
            if k > 0:
                sk += sum(vs[2][-k:])
            for l in range(N + 1 - i - j - k):
                if i * w1 + j * (w1 + 1) + k * (w1 + 2) + l * (w1 + 3) > W:
                    break
                sl = sk               
                if l > 0:
                    sl += sum(vs[3][-l:])
                ans = max(ans, sl)
print(ans)