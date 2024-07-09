from copy import deepcopy
from decimal import Decimal
n = int(input())
a = [int(Decimal(input()) * (pow(10, 9))) for i in range(n)]
l = [[0] * 19 for i in range(19)]
ans = 0
for i in a:
    cnt2 = 0
    i2 = deepcopy(i)
    while i2 % 2 == 0 and cnt2 < 18:
        i2 //= 2
        cnt2 += 1
    cnt5 = 0
    i5 = deepcopy(i)
    while i5 % 5 == 0 and cnt5 < 18:
        i5 //= 5
        cnt5 += 1
    ans += l[19 - cnt2 - 1][19 - cnt5 - 1]
    for i in range(cnt2 + 1):
        for j in range(cnt5 + 1):
            l[i][j] += 1
print(ans)