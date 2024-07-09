#147_D
n = int(input())
A = list(map(int, input().split()))
ans = 0
mod = 10 ** 9 + 7

for i in range(60):
    s = sum([(a >> i) & 1 for a in A])
    ans = (ans + s * (n-s) * pow(2,i,mod)) % mod
print(ans)