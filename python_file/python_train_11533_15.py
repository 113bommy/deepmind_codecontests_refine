from collections import deque

H, W = map(int, input().split())
c1, c2 = map(int, input().split())
d1, d2 = map(int, input().split())
c1 += 1
c2 += 1
d1 += 1
d2 += 1
S = ["#"*(W+4)]*2 + ["##"+input()+"##" for _ in range(H)] + ["#"*(W+4)]*2

ans = [[10000000]*(W+4) for _ in range(H+4)]
ans[c1][c2] = 0
q = deque([[c1, c2]])

x = [[-1, 0], [0, -1], [0, 1], [1, 0]]

while q:
    h, w = q.popleft()
    
    for a, b in x:
        nh = h+a
        nw = w+b
        if S[nh][nw] == ".":
            if ans[nh][nw] > ans[h][w]:
                ans[nh][nw] = ans[h][w]
                q.appendleft([nh, nw])
    
    for a in range(-2, 3):
        for b in range(-2, 3):
            nh = h+a
            nw = w+b
            if S[nh][nw] == ".":
                if ans[nh][nw] > ans[h][w]+1:
                    ans[nh][nw] = ans[h][w]+1
                    q.append([nh, nw])

if ans[d1][d2] == 10000000:
    print(-1)
else:
    print(ans[d1][d2])