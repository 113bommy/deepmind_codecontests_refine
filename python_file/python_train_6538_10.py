from collections import deque
h,w = map(int,input().split())
mz = []
q = deque()
for i in range(h):
    mz.append(list(input()))
    ls = [[i,j,0] for j, a in enumerate(mz[-1]) if a == '#'] #i黒のところのindexをqueに追加
    q.extend(ls)


delta = [[-1,0],[0,-1],[1,0],[0,1]]
while q:
    y,x,c = q.popleft()
    for dy,dx in delta:
        if (0<= y+dy <h) and (0<=x+dx <w):
            if mz[y+dy][x+dx] == ".":
                mz[y+dy][x+dx]="#" #黒に置き換え
                q.append([y+dy,x+dx,c+1])

            else: #すでに黒なら訪問しなくてよい
                pass

print(c)#cは最後にpopされたcost
