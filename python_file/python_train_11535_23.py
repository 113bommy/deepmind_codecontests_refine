h,w = map(int, input().split())
a=[list(map(int,input().split())) for i in range(h)]
b=[list(map(int,input().split())) for i in range(h)]
d = [[0 for j in range(w)] for i in range(h)]
for i in range(h):
    for j in range(w):
        d[i][j] = abs(a[i][j]-b[i][j])

dp = [[0 for _ in range(6400)] for _ in range(h*w)]
dp[0][d[0][0]]=1

for i in range(h*w):
    nowh,noww = divmod(i,w)
    for k in range(6400):
        if not dp[nowh*w + noww][k]==1:
            continue
        nxth,nxtw=nowh+1, noww+1
        if nxtw<w:
            if k+d[nowh][nxtw] < 6400:
                dp[nowh*w + nxtw][k+d[nowh][nxtw]] = 1
            dp[nowh*w + nxtw][abs(k-d[nowh][nxtw])] = 1
        if nxth<h:
            if k+ d[nxth][noww]< 6400:
                dp[nxth*w + noww][k+d[nxth][noww]] = 1
            dp[nxth*w + noww][abs(k-d[nxth][noww])] = 1


for k in range(6400):
    if dp[-1][k]==1:
        print(k)
        exit()