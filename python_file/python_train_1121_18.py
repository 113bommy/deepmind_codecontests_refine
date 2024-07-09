# F - . (Single Dot)

import bisect
import sys
readline = sys.stdin.readline

N, M = map(int, readline().split())
INF = 10**9 + 1
s_X = set([-INF, 0, INF])
s_Y = set([-INF, 0, INF])

def compress(s):
    ls = list(s)
    ls.sort()
    return {e: i for i, e in enumerate(ls)}

ABC = []
for i in range(N):
    A, B, C = map(int, readline().split())
    ABC.append((A, B, C))
    s_Y.add(C)

DEF = []
for i in range(M):
    D, E, F= map(int, readline().split())
    DEF.append((D, E, F))
    s_X.add(D)

mapX = compress(s_X)
mapY = compress(s_Y)
l_X = list(mapX.keys())
l_Y = list(mapY.keys())
maxX = len(mapX)*2
maxY = len(mapY)*2

W = [[0] * maxY for _ in range(maxX)]

for A, B, C in ABC:
    A = mapX[l_X[bisect.bisect_left(l_X, A)]]
    B = mapX[l_X[bisect.bisect_right(l_X, B)-1]]
    C = mapY[C]
    A *= 2
    B *= 2
    C *= 2
    for j in range(A, B+1):
        W[j][C] = 1

for D, E, F in DEF:
    D = mapX[D]
    E = mapY[l_Y[bisect.bisect_left(l_Y, E)]]
    F = mapY[l_Y[bisect.bisect_right(l_Y, F)-1]]
    D *= 2
    E *= 2
    F *= 2
    for j in range(E, F+1):
        W[D][j] = 1

#print(W)
q = []
q.append((mapX[0]*2, mapY[0]*2))
W[mapX[0]*2][mapY[0]*2] = 1
ans = 0
b_ans = True
while q:
    x, y = q.pop()
    if x == maxX or x == 0 or y == maxY or y == 0:
        b_ans = False
        break
    for (vx, vy) in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        nx = x + vx
        ny = y + vy
        if W[nx][ny] == 0:
            if nx%2==1 and ny%2==1:
                ex = l_X[(nx+1)//2] - l_X[(nx-1)//2]
                ey = l_Y[(ny+1)//2] - l_Y[(ny-1)//2]
                ans += ex * ey
                #print(nx, ny, ans)
            q.append((nx, ny))
            W[nx][ny] = 1

if b_ans == True:
    print(ans)
else:
    print('INF')
