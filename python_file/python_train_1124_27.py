import sys
F = sys.stdin
N, Q = map(int, F.readline().strip("\n").split())
s = F.readline().strip("\n")
O = [None] * Q
for i in range(Q):
    O[i] = list(map(str, F.readline().strip("\n").split()))

leftlow, lefthigh = 0, N
while lefthigh - leftlow > 1:
    mid = (lefthigh + leftlow)//2
    now = mid
    for place, move in O:
        if place == s[now]:
            if move == "L": now -= 1
            else: now += 1
            if now == -1 or now == N: break
    if now == -1:leftlow = mid
    else: lefthigh = mid

rightlow, righthigh = 0, N
while righthigh - rightlow > 1:
    mid = (righthigh + rightlow)//2
    now = mid
    for place, move in O:
        if place == s[now]:
            if move == "L":now -= 1
            else: now += 1
            if now == -1 or now == N: break
    if now == N:righthigh = mid
    else: rightlow = mid

print(righthigh - lefthigh)