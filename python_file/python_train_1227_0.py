from math import cos, sin, pi
from itertools import combinations
N, L = map(int, input().split())
T = [int(input()) for _ in range(N)]
PI2oL = 2*pi/L

csum, ssum = 0, 0
count = 0
for i, j in combinations(range(N), 2):
    count += 1
    mid1, num2 = (T[i] + T[j]) / 2, j - i - 1
    mid2, num1 = (mid1 + L/2) % L, N - num2 - 2
    csum += cos(PI2oL*mid1) * num1 + cos(PI2oL*mid2) * num2
    ssum += sin(PI2oL*mid1) * num1 + sin(PI2oL*mid2) * num2

print(csum/count/(N-2)*3, ssum/count/(N-2)*3)
