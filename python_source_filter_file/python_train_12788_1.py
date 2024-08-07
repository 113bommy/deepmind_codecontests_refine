A, B, C, D, E, F = map(int, input().split())

W = set()
for a in range(0, F+1, 100*A):
    for b in range(0, F+1-a, 100*B):
        W.add(a+b)

S = set()
for c in range(0, F+1, C):
    for d in range(0, F+1-c, D):
        S.add(c+d)

rate = -1
for w in W:
    for s in S:
        if 0 < w+s <= F and s <= (E//100)*w:
            if s/(w+s) > rate:
                rate = s/(w+s)
                ans = w+s, s
                
print(ans[0], ans[1])