n = int(input())
arr = list(map(int, input().split()))
ans = arr[0]
for i in range(1, n):
    ans += abs(arr[i] - arr[i - 1])
print(ans)