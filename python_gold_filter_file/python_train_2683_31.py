n = int(input())
ans = 10**n - 9**n - 9**n + 8**n
print(ans%(10**9 + 7))