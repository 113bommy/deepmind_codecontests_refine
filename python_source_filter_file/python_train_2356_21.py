import sys

n = int(input())
arr = list(map(int, input().split()))
ans = 0
for i in range(1, n-1):
    if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
        ans += 1
    elif arr[i] < arr[i-1] and arr[i] < arr[i-1]:
        ans += 1

print(ans)