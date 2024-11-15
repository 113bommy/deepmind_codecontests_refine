from fractions import gcd

N, M = map(int, input().split())
s = input()
t = input()
g = gcd(N, M)
n, m = N//g, M//g

for i in range(g):
    if s[n*i] != t[m*i]:
        print(-1)
        exit()
print(N*M//g)