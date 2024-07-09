def calc(left, right, time, vmax):
    if left <= time and time <= right:
        return vmax
    elif time < left:
        return vmax + left - time
    else:
        return vmax + time - right

n = int(input())
t = list(map(int, input().split()))
v = list(map(int, input().split()))
tlst = [[0, t[0]]]
for i in range(1, n):
    start = tlst[-1][1]
    stop = start + t[i]
    tlst.append([start, stop])

tmax = sum(t)
vnow = 0
ans = 0
for i in range(1, 2*tmax+1):
    time = 0.5 * i
    vmin = 10**9
    for j in range(n):
        left, right = tlst[j][0], tlst[j][1]
        vmax = v[j]
        vmin = min(vmin, calc(left, right, time, vmax))
    vmin = min(vmin, calc(0, 0, time, 0))
    vmin = min(vmin, calc(tmax, tmax, time, 0))
    ans += 0.25 * (vmin + vnow)
    vnow = vmin
print(ans)