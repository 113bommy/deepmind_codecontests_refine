import bisect
import sys
input = sys.stdin.readline

INF = 10**12
n, q = [int(item) for item in input().split()]
a = [int(item) for item in input().split()]

# Calc cumrative sum
sum_even = [0] * (n + 1)
sum_odd = [0] * (n + 1)
sum_all = [0] * (n + 1)
for i, item in enumerate(a):
    if i % 2 == 0:
        sum_odd[i+1] = sum_odd[i] + a[i]
        sum_even[i+1] = sum_even[i]
    else:
        sum_even[i+1] = sum_even[i] + a[i]
        sum_odd[i+1] = sum_odd[i]
    sum_all[i+1] = sum_all[i] + a[i]

# Iterate in query
a.append(INF)
ans = []
for i in range(q):
    x = int(input())
    # Get div of aoki - takahashi
    # l: aoki takes, r: takahashi takes
    l = 0; r = n - 1
    while r - l > 1:
        m = (r + l) // 2
        rng = abs(x - a[m])
        t_num = n - m
        a_num = n - t_num - (bisect.bisect_left(a, x - rng))
        if t_num <= a_num + 1:
            r = m
        else:
            l = m
    rng = abs(x - a[r])
    t_num = n - r
    rest = n - 2 * t_num
    t_sum = sum_all[n] - sum_all[n - t_num]
    a_sum = sum_all[r] - sum_all[r - t_num]

    # Add stripe area
    if n - t_num * 2 > 0:
        if rest % 2 == 0:
            t_sum += sum_even[rest]
            a_sum += sum_odd[rest]
        else:
            t_sum += sum_odd[rest]
            a_sum += sum_even[rest]
    ans.append(t_sum)

print("\n".join([str(item) for item in ans]))