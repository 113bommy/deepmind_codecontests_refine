n = int(input())
a = [int(i) for i in input().split()]
ans = [1] * n 
for i in range(n - 1):
    k = a[i] / 2
    if a[i - 1] >= k:
        ans[i] = ans[i - 1] + 1
print(max(ans))