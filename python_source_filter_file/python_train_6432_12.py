N = int(input())
X = list(map(int, input().split()))
M = round(sum(X)/N)
ans = 0
for i in X:
    ans+=(i-M)*2
print(ans)