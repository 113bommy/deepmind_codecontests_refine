from itertools import accumulate
N = int(input())
t = [0]*2 + list(map(int, input().split())) + [0]
v = [0] + list(map(int, input().split())) + [0]
N += 3

at = list(accumulate(t))
T = at[-1]

s = [0]*(2*T+1)

minvs = []
for i in range(2*T+1):
    t = i*0.5
    minv = 10**10
    for j in range(N-1):
        if t < at[j]:
            tmpv = v[j] + (at[j]-t)
        elif at[j] <= t and t <= at[j+1]:
            tmpv = v[j]
        else:
            tmpv = v[j] + (t-at[j+1])
        minv = min(minv, tmpv)
    minvs.append(minv)
ans = 0.0
for i in range(2*T):
    ans += (minvs[i]+minvs[i+1])*0.25
print(ans)
