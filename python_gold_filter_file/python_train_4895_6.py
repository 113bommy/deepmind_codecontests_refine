import sys

n = int(input())
mx = -2000000000
mn = int(input())

for i in map(int, sys.stdin.readlines()):
    mx = max(mx, i - mn)
    mn = min(mn, i)

print(mx)