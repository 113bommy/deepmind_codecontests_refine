#2分探索
#md/cで交点が定まらない時の対案
n,k = map(int, input().split( ))
m = [tuple(map(int, input().split( ))) for i in range(n)]
#そもそも設定はn枚すべて焼く必要はない
mx = 10**15
mn = 0
from math import sqrt
def solve(x1, y1, r1, x2, y2, r2):
    rr0 = (x2 - x1)**2 + (y2 - y1)**2
    xd = x2 - x1
    yd = y2 - y1
    rr1 = r1**2; rr2 = r2**2
    cv = (rr0 + rr1 - rr2)
    if max(r1,r2,sqrt(rr0))*2>r1+r2+sqrt(rr0):
        return (x1,y1),(x2,y2)
    sv = sqrt(4*rr0*rr1 - cv**2)
    return (
        (x1 + (cv*xd - sv*yd)/(2.*rr0), y1 + (cv*yd + sv*xd)/(2.*rr0)),
        (x1 + (cv*xd + sv*yd)/(2.*rr0), y1 + (cv*yd - sv*xd)/(2.*rr0)),
    )

#flag で breakしてたのが煩雑すぎて追えていなかったらしい
while mx-mn>10**(-6) or mx-mn>10**(-7)*mx:#mx大きい時に安易に設定すると到達しない？
    md = (mx+mn)/2
    cnt = 0
    for i in range(n):##中心選ぶケースが抜けてる
        pi0,pi1 = m[i][0],m[i][1]
        tmp = 0
        for l in range(n):#kはすでに使っている変数
            if m[l][2]*sqrt(((pi0-m[l][0])**2) + ((pi1-m[l][1])**2))<=md+0.000000001:
                tmp += 1
        if cnt<tmp:
            cnt = tmp

    for i in range(n):
        for j in range(i+1,n):##range(i)だとi=0で止まって何もしない

            p = solve(m[i][0],m[i][1],md/m[i][2], m[j][0],m[j][1],md/m[j][2])

            for pi in p:
                tmp = 0
                for l in range(n):#kはすでに使っている変数
                    if (((pi[0]-m[l][0])**2) + ((pi[1]-m[l][1])**2))**(1/2)<=md/m[l][2]+0.000000001:##ここで誤差認めなかったせいらしい
                        tmp += 1
                if cnt<tmp:
                    cnt = tmp

    if cnt>=k:
        mx = md
    else:
        mn = md
print(mx)
