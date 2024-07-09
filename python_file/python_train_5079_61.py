import bisect, math
N,D,A = map(int,input().split())
enemy = list(list(map(int,input().split()))for i in range(N))
enemy.sort()

damege = [0]*N

ans = 0
p = 0
while p < N:
    if p>=1:
        damege[p] += damege[p-1]
    enemy[p][1] -= damege[p]
    if enemy[p][1] <= 0:
        p += 1 
        continue
    d = math.ceil(enemy[p][1]/A)
    ans += d
    d *= A
    r = bisect.bisect_right(enemy,[enemy[p][0]+D*2,10**9+7])
    if r!=N:
        damege[r]-=d
    damege[p] += d
    p+=1
print(ans)

