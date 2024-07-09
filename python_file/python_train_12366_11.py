h,w,k =map(int,input().split())
ma = []
for i in range(h):
    ma.append(list(map(int,list(input()))))
ans = [0]*2**(h-1)
for i in range(2**(h-1)):
    idx = [0]*h #縦の何枚目か
    group = 0
    for j in range(h):
        idx[j] = group
        if (i>>j & 1):
            group +=1
    ans[i] += idx[-1]#h方向の分割
    n = idx[-1]+1#縦に何枚あるか
    cnt = [0]*n ##各ブロックの白チョコの数
    div_w = 0 #w方向の分割
    for e in range(w):
        temp = [0]*n #一時的な列を保存
        for j in range(h):
            p = idx[j]
            cnt[p] += ma[j][e]
            temp[p] += ma[j][e]
        if max(cnt) >k:
            div_w +=1
            cnt = temp
        if max(temp) >k:#この時h方向の分割そのものがだめ
            div_w = 10**9
            break
    ans[i] += div_w
print(min(ans))
