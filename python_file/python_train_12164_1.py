# -*- coding: utf-8 -*-

from itertools import accumulate

N = int(input())
T = list(map(int, input().split()))
V = list(map(int, input().split()))

clock = [0] + list(accumulate(T))
t_sum = sum(T)
mn_f = 0
ans = 0
for t in range(2 * t_sum):
    t /= 2
    mn = min(t, t_sum - t)
    for i in range(1, len(clock)):
        v = V[i-1]
        if t < clock[i-1]:
            v_max = v + clock[i-1] - t
        elif clock[i-1] <= t <= clock[i]:
            v_max = v
        else:
            v_max = v + t - clock[i]
        mn = min(mn, v_max)
    ans += (mn_f + mn) * 0.25
    mn_f = mn

ans += mn_f * 0.25

print(ans)
