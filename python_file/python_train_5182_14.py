n, k = map(int, input().split())
p = list(map(int, input().split()))
c = list(map(int, input().split()))
maximum = -10**9
for i in range(n):
    totalfull = 0; totalcut = 0; count = 0; location = i
    maximumfull = -10**9; maximumcut = -10**9
    for j in range(min(n, k)):
        location = p[location]-1
        totalfull += c[location]
        maximumfull = max(maximumfull, totalfull)
        count += 1
        if location == i: break
    for j in range(k%count):
        location = p[location]-1
        totalcut += c[location]
        maximumcut = max(maximumcut, totalcut)
    maximum = max(maximum, max(maximumfull, max((k//count-1)*totalfull+maximumfull, k//count*totalfull+maximumcut)))
print(maximum)