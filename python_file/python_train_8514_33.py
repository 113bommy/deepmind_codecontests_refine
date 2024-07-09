#https://atcoder.jp/contests/abc138/submissions/8926003

S = input()
T = input()
if not set(T) <= set(S):
    print(-1)
    exit()
now = -1
rep = 0
for t in T:
    now = S.find(t,now+1)
    if now == -1:
        rep += 1
        now = S.find(t)
print(rep*len(S)+now+1)
