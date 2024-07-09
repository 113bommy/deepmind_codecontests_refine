from collections import deque
H,W=map(int,input().split())
A=[list(input()) for _ in range(H)]

q=deque()

#黒マスを探す
for w in range(W):
    for h in range(H):
        if A[h][w]=='#':
            q.append((h,w,0))

#BFS
ans=0
while q:
    h,w,d = q.popleft()
    ans=max(ans,d)
    for dh,dw in [(0,1),(1,0),(0,-1),(-1,0)]:
        nh,nw = h+dh, w+dw
        if nh<0 or nh>=H or nw<0 or nw>=W:
            continue
        if A[nh][nw]=='#':
            continue
        A[nh][nw]='#'
        q.append((nh,nw,d+1))

print(ans)