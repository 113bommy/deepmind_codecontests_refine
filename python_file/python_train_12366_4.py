h,w,k = list(map(int,input().split()))
arr = [[int(i) for i in input()] for _ in range(h)]

from itertools import product
ans = 2000

for idx,cond in enumerate(product((True,False),repeat=h-1)):
    div = sum(cond)
    spl = [arr[0][:]]
    for i in range(h-1):
        if cond[i]:
            spl.append(arr[i+1][:])
        else:
            spl[-1] = [spl[-1][j] + arr[i+1][j] for j in range(w)]
    num = len(spl)
    cnt = [0]*num
    
    for v in range(w):
        tmp = [spl[i][v] for i in range(num)]
        if max(tmp) > k:
            break
        if max([cnt[i] + tmp[i] for i in range(num)]) > k:
            div += 1
            cnt = tmp[:]
        else:
            cnt  = [cnt[i] + tmp[i] for i in range(num)]
    else:    
        ans = min(ans,div)
            
print(ans)