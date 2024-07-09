import sys
from fractions import gcd
input = sys.stdin.readline

n = input()
arr = list(map(int, input().split()))
tmp = arr[0]
for i in arr:
    tmp = tmp*i//gcd(tmp,i)
print(sum(tmp//a for a in arr) % (10**9+7))