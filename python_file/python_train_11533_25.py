from collections import deque
H,W = map(int,input().split())
Ch,Cw = map(int,input().split())
Dh,Dw = map(int,input().split())
S = []
for _ in range(H):
    S.append(list(input()))

warp = [[-1 for i in range(W)]for j in range(H)]

Q = deque([[Ch-1,Cw-1,0]])

while(len(Q) != 0):
    x,y,cnt = Q.popleft()

    if(warp[x][y] != -1):   #skip
        continue

    warp[x][y] = cnt        #ワープ魔法の必要回数

    for tx in range(-2,3):
        for ty in range(-2,3):
            nx = x+tx
            ny = y+ty

            if(0 <= nx < H and 0<= ny < W and S[nx][ny]=="."):
                if(abs(tx)+abs(ty) == 1):#徒歩で行けるなら前に
                    Q.appendleft([nx,ny,cnt])
                elif(abs(tx)+abs(ty)>=2):#ワープ魔法必要なら後ろに
                    Q.append([nx,ny,cnt+1])

print(warp[Dh-1][Dw-1])