n, m = list(map(int, input().split()))
print(max(n - sum(list(map(int, input().split()))), 0))